/**
 * @class dimensions
 * @description This class is used to create multidimensional arrays.
 * @author flamebousteur
 * @version 1.0.0
 * @license GPL-3.0-or-later
 * /!\ This code is not tested yet. /!\
 */
class dimensions {
	public:
        unsigned int* dim;
	    unsigned int dataLength;
	    int* buffer;
        dimensions(unsigned int* dim, unsigned int dataLength) {
            this->dim = dim;
            this->dataLength = dataLength;
            // the lenght of the buffer is the product of all the numbers in the dim array
            int length = 0;
            for (int i = 0; i < sizeof(dim); i++) length *= dim[i];
            this->buffer = new int[length];
        }
};