#!/bin/bash

Color_Off='\e[0m'       # Text Reset
IYellow='\e[0;93m'      # Yellow
BIBlue='\e[1;94m'       # Blue
IRed='\e[0;91m'         # Red
On_Black='\e[40m'       # Black
IGreen='\e[0;92m'       # Green

if [ -z $CXX ]; then
  CXX=g++
fi

check() {
  dir=$1
  pushd $dir > /dev/null 2>&1

  srcs=$(ls *.cc 2> /dev/null | grep -v template.cc)
  if [ -z "$srcs" ]; then
    popd > /dev/null 2>&1
    return 1
  fi

  title=$(git log --pretty=oneline . | head -n1 | cut -d' ' -f 2-)
  echo -e ${BIBlue}$title${Color_Off}
  echo

  if [ ! -f input.txt -o ! -f output.txt ]; then
    echo -e "${IYellow}W: No input or output files${Color_Off}"
    echo
    popd > /dev/null 2>&1
    return 2
  fi

  ok=0
  for src in $srcs
  do
    echo "> $src"
    if $CXX -o bin $src -lm -lcrypt -O2 -pipe -DONLINE_JUDGE > /dev/null 2>&1
    then
      /usr/bin/time -f "%E real, %U user, %S sys" -o .time.txt ./bin < input.txt > .cmp-output.txt
      cat .time.txt | sed 's/^/  /'
      diff output.txt .cmp-output.txt > /dev/null 2>&1
      if [ $? -ne 0 ]; then
        echo -e "  ${IRed}E: Invalid result${Color_Off}"
      else
        echo -e "  ${IGreen}OK${Color_Off}"
        ok=1
      fi
    else
      echo -e "  ${IRed}E: Compile error${Color_Off}"
    fi
    echo
  done

  popd > /dev/null 2>&1

  if [ $ok -eq 0 ]; then
    return 3
  fi
}

find . -type d -not -iwholename '*.git*' | while read dir
do
  check $dir
  if [ $? -eq 3 ]; then
    exit 3
  fi
done

