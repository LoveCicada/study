#!/usr/bin/env python
# -*- coding: utf-8 -*-

import argparse
import multiprocessing
import os
import shutil
import subprocess
import sys
from xml.dom import minidom


def check_vs_project(checker, project_dir, exclude_paths):
    for file in os.listdir(project_dir):
        if file.endswith('.sln'):
            project_file = os.path.join(project_dir, file)
            check_cmd = [checker,
                            '--addon=threadsafety',
                             '-j', f'{multiprocessing.cpu_count()}',
                             '--platform=win64',
                             '--std=c++17',
                             '--output-file=win64.analyze.xml', '--xml', '2',
                             f'--project={project_file}']
            for exclude_path in exclude_paths:
                exclude_path = exclude_path.strip()
                if len(exclude_path) > 0:
                    check_cmd.append('-i')
                    if not os.path.exists(exclude_path):
                        exclude_path = os.getcwd() + exclude_path
                    check_cmd.append(exclude_path.replace('\\', '/'))
            subprocess.check_call(args=check_cmd)
            break

def check_project(project_dir, excludes):
    checker = shutil.which('cppcheck')
    if os.name == 'nt':
        if not checker:
            checker = 'C:/Program Files/Cppcheck/cppcheck.exe'
        try:
            exclude_paths = excludes.split(';')
        except:
            exclude_paths = 0
        check_vs_project(checker, project_dir, exclude_paths)

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--project-dir', dest='project_dir')
    parser.add_argument('--excludes', dest='excludes')
    args = parser.parse_args()
    if not args.project_dir:
        args.project_dir = os.path.join(os.getcwd(), 'build')
    check_project(args.project_dir, args.excludes)
    sys.exit(0)
