#!/bin/bash

# script for project 2 example tests

program="project2"
images="byu cheese face fish horses"
testdir="images"

gcc -Wall -Werror -g bmpFilter.c -o $program

for test in $images ; do
    echo "Running test" $test
    inputfile=$testdir/original/orig-$test.bmp
    outputfile=$testdir/out-grayscale/out-grayscale-$test.bmp
    answerfile=$testdir/grayscale/grayscale-$test.bmp

    ./$program -g <$inputfile >$outputfile

    diff $answerfile $outputfile

    # rm $outputfile
done

rm $program