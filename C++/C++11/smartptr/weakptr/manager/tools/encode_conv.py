#!/usr/bin/env python
# -*- coding: utf-8 -*-
import codecs
import os
import sys
import time
import chardet

convertfiletypes = [
  ".cpp",
  ".cxx",
  ".cc",
  ".cu",
  ".cuh",
  ".c",
  ".h",
  ".hpp",
  ".hxx",
  ".mm",
  ".m",
  ".swift",
  ".java"
  ".asm"
  ".nasm"
  ".masm"
  ".S"
  ]

def check_need_convert(filename):
    for filetype in convertfiletypes:
        if filename.lower().endswith(filetype):
            return True
    return False

total_cnt = 0
success_cnt = 0
unkown_cnt = 0
def convert_encoding_to_utf_8_sig(filename):
    global total_cnt,success_cnt,unkown_cnt
    # Backup the origin file.

    # convert file from the source encoding to target encoding
    content = codecs.open(filename, 'rb').read()
    detect = chardet.detect(content)
    source_encoding = detect['encoding']
    confidence = detect['confidence']
    if source_encoding.lower().startswith('iso-8859') and confidence < 0.9:
        source_encoding = 'GBK'
    total_cnt+=1
    if source_encoding == None:
        unkown_cnt+=1
        return
    print(source_encoding, filename)
    if source_encoding != 'UTF-8-SIG':
        str_content = content.decode(source_encoding)
        backup_filename = filename + '.(' + str(time.perf_counter()) + ')' + '.old'
        codecs.open(backup_filename, 'wb').write(content)
        try:
            codecs.open(filename, 'w', encoding='UTF-8-SIG').write(str_content)
            os.remove(backup_filename)
        except Exception as e:
            print('conv error：', e)
        success_cnt+=1

def convert_dir(root_dir):
    if os.path.exists(root_dir) == False:
        print("[error] dir:",root_dir,"do not exit")
        return
    print("work in", root_dir)
    for root, dirs, files in os.walk(root_dir):
        for f in files:
            if check_need_convert(f):
                filename = os.path.join(root, f)
                try:
                    convert_encoding_to_utf_8_sig(filename)
                except Exception as e:
                    print("WA",filename,e)
    print("find total:",total_cnt,"success:",success_cnt,"unkown_cnt",unkown_cnt)
    return success_cnt + unkown_cnt

if __name__ == '__main__':
    if len(sys.argv) == 1:
        dir = os.getcwd() + '/source'
    else:
        dir = sys.argv[1]
    result = convert_dir(dir)
    sys.exit(result)