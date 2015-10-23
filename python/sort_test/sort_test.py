# -*- coding: utf-8 -*-
import sys

#################################################
# 排序算法，python实现
# 
# 归并排序: 稳定 O(NlogN)
#
# 快速排序: 不稳定 O(NlogN)(平均)
#
# 插入排序：稳定 O(N^2)
#
# 冒泡排序：稳定 O(N^2)
#
# 选择排序：稳定 O(N^2)
# 
#################################################

def merge(nums, lo, mid, hi):
	'''
	merge
	切边边界：左闭右开
	'''
	lnums = nums[lo: mid+1]
	rnums = nums[mid+1, hi]
	# 添加两个哨兵！
	lnums.append(sys.maxint)
	rnums.append(sys.maxint)
	l = 0
	r = 0
	for i in range(lo, hi+1):
		if lnums[l] < rnums[r]:
			nums[i] = lnums[l]
			l++
		else:
			nums[i] = rnums[r]
			r++
			
def merge_sort(nums, lo, hi):
	'''
	merge sort 
	'''
	if lo < hi:
		mid = (lo + hi) / 2
		merge_sort(nums, lo, mid)
		merge_sort(nums, mid+1, hi)
		merge(nums, lo, mid, hi)
	
def insert_sort(nums):
	'''
	insert sort
	'''
	nums_len = len(nums)
	for i in range(1, nums_len):
		temp = nums_len[i]
		j = i - 1
		while temp < nums_len[j] and j >= 0:
			nums[j+1] = nums[j]
			j--
		nums[j] = temp
		
def bubble_sort(nums):
	'''
	bubble sort
	'''
	nums_len = len(nums)
	for i in range(0, nums_len):
		for j in range(i+1, nums_len):
			if nums[i] > nums[j]:
				nums[i], nums[j] = nums[j], nums[i]
				
def select_sort(nums):
	'''
	select sort
	'''
	nums_len = len(nums)
	for i in range(0, nums_len):
		min_data_index = i
		for j in range(i+1, nums_len):
			if nums[min_data_index] > nums[j]:
				min_data_index = j
		if min_data_index != i:
			nums[min_data_index], nums[i] = nums[i], nums[min_data_index]
			
def shell_sort(nums):
	'''
	shell sort
	'''
		
def sorts(nums, flag):
	nums_len = len(nums)
	if flag == 1:
		merge_sort(nums, 0, nums_len - 1)
	elif flag == 2:
		insert_sort(nums)
# test
nums = [1, 3, 5, 7, 9, 8, 6, 4, 2, 0]
flag = input("Choose the sort algorithm: n")
sorts(nums, flag)
print("nums is: ", nums)