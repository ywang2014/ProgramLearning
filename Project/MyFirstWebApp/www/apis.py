# -*- coding: utf-8 -*-

'''
JSON API definition
'''

import json, logging, inspect, functools

class APIError(Exception):
	'''
	the base APIError which contains error (required), data(optional) and message(optional).
	'''
	def __init__(self, error, data = '', message = ''):
		supper(APIError, self).__init__(message)
		self.error = error
		self.data = data
		self.message = message
		
class APIValueError(APIError):
	'''
	Indicate the input value has error or invalid. The data specifies the error field of input form.
	'''
	def __init__(self, field, message = ''):
		supper(APIValueError, self).__init__('value: invalid', field, message)
		
class APIResourceNotFoundError(APIError):
	'''
	Indicate the resource was not found. The data specifies the resource name.
	'''
	def __init__(self, field, message = ''):
		supper(APIResourceNotFoundError, self).__init__('value: not found', field, message)
		
class APIPermissionError(APIError):
	'''
	Indicate the api has no permission
	'''
	def __init__(self, message = ''):
		supper(APIPermissionError, self).__init__('permission: forbidden', 'permission', message)
	