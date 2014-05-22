#encoding: utf-8
#!/usr/bin/env Python

import os
import re

#path walk and get list of dirs and pages
def get_dirs_and_files(path):
    dirs = []
    files = []      
    for i in os.walk(path):
        dirs.append(i[0])
        for ii in i[2]:
            files.append(i[0]+os.sep+ii)    #filenames with paths
    return dirs,files

#path walk and get line count
def get_lines(path):
    dirs,files = get_dirs_and_files(path)
    lines = 0
    for f in files:
        lines += len(open(f).readlines())
    return lines

#path walk and get char count
def get_chars(path):
    dirs,files = get_dirs_and_files(path)
    chars = 0
    for f in files:
        for l in open(f).readlines():
            chars += len(l.strip())
    return chars


#search content with pattern and return times of occurence
def regex_search(file,regex):
    count = 0
    for l in open(file).readlines():
        match = regex.search(l)
        if match:
            count += 1
    return count
def regex_search_path(path,regex):
    count = 0
    dirs, files = get_dirs_and_files(path)
    for f in files:
        count += regex_search(f,regex)
    return count



if __name__ == '__main__':
    path = "/var/www/html/dokuwiki/data/pages"

    dirs,files = get_dirs_and_files(path)

    print "path:",path
    print "namespace count:",len(dirs)-1 #exclude path itself
    
    draft = regex_search_path(path,re.compile(r'<WRAP center round alert'))
    constructing = regex_search_path(path,re.compile(r'<WRAP center round todo'))
    published = regex_search_path(path,re.compile(r'<WRAP center round tip'))

    print "page count:",len(files)," (draft:",draft," constructing:",constructing," published:",published," default:",7," unknown:",len(files)-draft-constructing-published-7,")" #7 default pages without status
    
    title_1_and_above = regex_search_path(path,re.compile(r'={2}.*={2}'))
    title_2_and_above = regex_search_path(path,re.compile(r'={3}.*={3}'))
    title_3_and_above = regex_search_path(path,re.compile(r'={4}.*={4}'))
    title_4_and_above = regex_search_path(path,re.compile(r'={5}.*={5}'))
    title_5_and_above = regex_search_path(path,re.compile(r'={6}.*={6}'))
    title_6_and_above = regex_search_path(path,re.compile(r'={7}.*={7}'))    #not a title

    title1 = title_1_and_above-title_2_and_above
    title2 = title_2_and_above-title_3_and_above
    title3 = title_3_and_above-title_4_and_above
    title4 = title_4_and_above-title_5_and_above
    title5 = title_5_and_above-title_6_and_above
    titles = title5+title4+title3+title2+title1

    print "title count:",titles," (lv5:",title5," lv4:",title4," lv3:",title3," lv2:",title2," lv1:",title1,")"
    print "line count:",get_lines(path)

    links = regex_search_path(path,re.compile(r'\[{2}.*]{2}'))
    pics = regex_search_path(path,re.compile(r'\{{2}.*}{2}'))
    print "link count:",links
    print "picture count:",pics

    print "char count:",get_chars(path)