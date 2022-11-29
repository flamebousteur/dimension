"""
@class dimensions
@description This class is used to create multidimensional arrays.
@author flamebousteur
@version 1.0.0
@license GPL-3.0-or-later
/!\ This code is not tested yet. /!\
"""

class dimensions:
	"""
	@brief create multidimensional array
	@constructor
	@param {Array} dim array of numbers each number represents the size of a dimension
	@param {number} dataLenght
	@returns {dimensions} dimensions object
	"""
	def __init__(self, dim = [], dataLenght = 1):
		self.dim = dim
		self.dataLenght = dataLenght
		""" the lenght of the buffer is the product of all the numbers in the dim array """
		Lenght = 0
		for i in range(len(dim)): Lenght *= dim[i]
		self.buffer = [0] * Lenght * dataLenght
		
	"""
	@brief returns the index of the buffer for the given coordinates
	@param {Array} coordinates array of numbers each number represents the coordinate of a dimension
	@returns {number} index in the buffer
	"""
	def getIndex(self, coordinates):
		index = 0
		for i in range(len(coordinates)):
			index += coordinates[i] * self.dim[i]
		return index