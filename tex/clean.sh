#!/bin/bash

rm `ls |egrep -v '(*.tex|*.sh|*.dvi|*.md)'`
