#!/bin/bash

source test_utils.sh

vec_class=$(cat ../myVectorName.txt)

# Pass the name of the input and the name of the output file
# Must apply all necessary substitutions on the input file
# and produce the output file
function cpp_replace () {
  sed -e "s/VEC_NAME/$vec_class/g" $1 > $2
}

# Student folder, homework name
student_folder='../'
cpp_main "$student_folder" "hw3" "hw3_grader.h.in"
