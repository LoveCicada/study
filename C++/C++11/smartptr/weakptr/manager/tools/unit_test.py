#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import sys
import subprocess
import platform

def check_is_test(filename):
    if platform.system().lower() == 'windows':
        return filename.lower().startswith('test') and filename.lower().endswith('.exe')
    else:
        return filename.lower().startswith('test')

def run_test(root_dir):
    if os.path.exists(root_dir) == False:
        print("[error] dir:",root_dir," does not exit")
        return -1
    error = 0
    for root, dirs, files in os.walk(root_dir):
        for f in files:
            if check_is_test(f):
                filename = os.path.join(root, f)
                print(f)
                if os.access(filename, os.X_OK):
                    report_name = os.path.splitext(filename)[0] + '.xml'
                    ret = subprocess.call(args=[filename, '--gtest_output=xml:'+report_name])
                    if ret != 0:
                        error += 1
    return error

if __name__ == '__main__':
    if len(sys.argv) == 1:
        dir = os.getcwd() + '/solution/win64/output/Debug'
    else:
        dir = sys.argv[1]
    ret = run_test(dir)
    sys.exit(ret)
