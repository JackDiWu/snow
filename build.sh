#!/bin/zsh
###
 # @Author: Jack
 # @Date: 2023-10-29 12:12:15
 # @LastEditors: Jack
 # @LastEditTime: 2023-10-29 12:32:04
### 
make clean
flex snow.lex
bison snow.bison
make