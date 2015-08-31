# -*- coding: utf-8 -*-

# Quine: is a non-empty computer program which takes no input and produces a copy of its own source code as its only output.
# self-replicating programs  self-reproducing programs  self-copying programs

s = 's = %r\nprint(s%s)'
print(s%s)