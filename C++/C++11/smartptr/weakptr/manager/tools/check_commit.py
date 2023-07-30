#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import subprocess

if __name__ == '__main__':
    print('- Check merge commits')
    proc = subprocess.Popen(["git", "log", "--merges", "-n", "1", "FETCH_HEAD..HEAD"], stdout=subprocess.PIPE, encoding='UTF-8')
    proc.wait()
    out = proc.stdout.read()
    if out != '':
        print('\n' + out + '\n')
        print('Has merge commit! This is not allowed.')
        sys.exit(1)
    print('- Check merge commits OK.')
    sys.exit(0)
