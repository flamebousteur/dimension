<?php
/**
 * @class dimensions
 * @description This class is used to create multidimensional arrays.
 * @author flamebousteur
 * @version 1.0.0
 * @license GPL-3.0-or-later
 * /!\ This code is not tested yet. /!\
 */
class dimensions {
    public Array $dim;
	public int $dataLenght;
    public Array $buffer;

    /**
	 * @brief create multidimensional array
	 * @constructor
	 * @param {Array} dim array of numbers each number represents the size of a dimension
	 * @param {number} dataLenght
	 * @returns {dimensions} dimensions object
	 * @example let dim = new dimensions([2, 2, 2], 1);
	 */
    public function __constructor($dim, $dataLenght) {
        $this->$dim = $dim;
        $this->$dataLenght = $dataLenght;
        // the lenght of the buffer is the product of all the numbers in the dim array
        $lenght = 0;
        for ($i = 0; $i < count($dim); $i++) $lenght *= $dim[$i];
        $this->$buffer = new Array($lenght * $dataLenght);
    }
}