/**
 * @class dimensions
 * @description This class is used to create multidimensional arrays.
 * @author flamebousteur
 * @version 1.0.0
 * @license GPL-3.0-or-later
 * /!\ This code is not tested yet. /!\
 */
class dimensions {
	public int[] dim;
	public int dataLength;
	public int[] buffer;

	/**
	 * @brief create multidimensional array
	 * @constructor
	 * @param {Array} dim array of numbers each number represents the size of a dimension
	 * @param {number} dataLenght
	 * @returns {dimensions} dimensions object
	 * @example let dim = new dimensions([2, 2, 2], 1);
	 */
	public static main(int[] dim, int dataLength) {
		this.dim = dim.length;
		this.dataLength = dataLength;
		// the lenght of the buffer is the product of all the numbers in the dim array
		int length = 0;
		for (int i = 0; i < dim.length; i++) length *= dim[i];
		this.buffer = new int[this.dim];
	}
}