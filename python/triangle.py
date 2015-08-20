#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def triangle():
    L = [1]
    yield L
    while True:
        L.append(1)
        yield L
        L = [L[i] + L[i+1] for i in range(0,len(L)-1)]
        L.insert(0, 1)


