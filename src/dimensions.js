/**
 * @class dimensions
 * @description This class is used to create multidimensional arrays.
 * @author flamebousteur
 * @version 1.0.0
 * @license GPL-3.0-or-later
 * /!\ This code is not tested yet. /!\
 */
class dimensions {
	dim;
	dataLengh;
	buffer;
	/**
	 * @brief create multidimensional array
	 * @constructor
	 * @param {Array} dim array of numbers each number represents the size of a dimension
	 * @param {number} dataLenght
	 * @returns {dimensions} dimensions object
	 * @example let dim = new dimensions([2, 2, 2], 1);
	 */
	constructor(dim = [], dataLenght = 1) {
		this.dim = dim;
		this.dataLenght = dataLenght;
        // the lenght of the buffer is the product of all the numbers in the dim array
		this.buffer = new Uint8Array(dim.reduce((a, b) => a * b) * dataLenght);
	}

	/**
	 * @brief returns the index of the buffer for the given coordinates
	 * @param {Array} coordinates array of numbers each number represents the coordinate of a dimension
	 * @returns {number} index in the buffer
	 */
	getIndex(coordinates) {
		let index = 0;
		for (let i = 0; i < coordinates.length; i++) index += coordinates[i] * this.dim.slice(i + 1).reduce((a, b) => a * b) * this.dataLenght;
		return index;
	}

	/**
	 * @brief returns the coordinates of the buffer for the given index
	 * @param {number} index index in the buffer
	 * @returns {Array} array of numbers each number represents the coordinate of a dimension
	 */
	getCoordinates(index) {
		let coordinates = [];
		for (let i = 0; i < this.dim.length; i++) {
			let dim = this.dim.slice(i + 1).reduce((a, b) => a * b) * this.dataLenght;
			coordinates.push(Math.floor(index / dim));
			index -= coordinates[i] * dim;
		}
		return coordinates;
	}

	/**
	 * @brief returns the value of the buffer for the given coordinates
	 * @param {Array} coordinates array of numbers each number represents the coordinate of a dimension
	 * @returns {number} value in the buffer
	 */
	get(coordinates) {
		let data = [];
		for (let i = 0; i < this.dataLenght; i++) data.push(this.buffer[this.getIndex(coordinates) + i]);
		return data;
	}

	/**
	 * @brief sets the value of the buffer for the given coordinates
	 * @param {Array} coordinates array of numbers each number represents the coordinate of a dimension
	 * @param {number} value value in the buffer
	 * @returns {number} value in the buffer
	 */
	set(coordinates, value) {
		for (let i = 0; i < this.dataLenght; i++) this.buffer[this.getIndex(coordinates) + i] = value[i];
		return value;
	}

	/**
	 * @brief returns the value of the buffer for the given index
	 * @param {number} index index in the buffer
	 * @returns {number} value in the buffer
	 */
	getIndexValue(index) {
		let data = [];
		for (let i = 0; i < this.dataLenght; i++) data.push(this.buffer[index + i]);
		return data;
	}

	/**
	 * @brief sets the value of the buffer for the given index
	 * @param {number} index index in the buffer
	 * @param {number} value value in the buffer
	 * @returns {number} value in the buffer
	 */
	setIndexValue(index, value) {
		for (let i = 0; i < this.dataLenght; i++) this.buffer[index + i] = value[i];
		return value;
	}

	/**
	 * @brief fill data into tow coordinates
	 * @param {Array} coordinates1 array of numbers each number represents the coordinate of a dimension
	 * @param {Array} coordinates2 array of numbers each number represents the coordinate of a dimension
	 * @param {number} value value in the buffer
	 * @returns {number} value in the buffer
	 */
	fill(coordinates1, coordinates2, value) {
		for (let i = 0; i < coordinates1.length; i++) {
			for (let j = coordinates1[i]; j <= coordinates2[i]; j++) {
				let coordinates = coordinates1.slice();
				coordinates[i] = j;
				this.set(coordinates, value);
			}
		}
		return value;
	}

	/**
	 * @brief get data from tow coordinates
	 * @param {Array} coordinates1 array of numbers each number represents the coordinate of a dimension
	 * @param {Array} coordinates2 array of numbers each number represents the coordinate of a dimension
	 * @returns {Array} array of numbers each number represents the value of a coordinate
	 */
	gets(coordinates1, coordinates2) {
		let data = [];
		for (let i = 0; i < coordinates1.length; i++) {
			for (let j = coordinates1[i]; j <= coordinates2[i]; j++) {
				let coordinates = coordinates1.slice();
				coordinates[i] = j;
				data.push(this.get(coordinates));
			}
		}
		return data;
	}
}