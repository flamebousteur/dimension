#ifdef __cplusplus
extern "C" {
#endif

/**
 * @description This code is used to create multidimensional arrays.
 * @author flamebousteur
 * @version 1.0.0
 * @license GPL-3.0-or-later
 * /!\ This code is not tested yet. /!\
 */
typedef struct {
	unsigned int *dim;
	unsigned int dataLenght;
    int *buffer;
} dimensions;

/**
 * @brief create multidimensional array
 * @constructor
 * @param {Array} dim array of numbers each number represents the size of a dimension
 * @param {number} dataLenght
 * @returns {dimensions} dimensions object
 * @example dimensions dim = new_dimensions([2, 2, 2], 1);
 */
dimensions new_dimensions(unsigned int *dim, unsigned int dataLenght) {
    dimensions d;
    d.dim = dim;
    d.dataLenght = dataLenght;
    // the lenght of the buffer is the product of all the numbers in the dim array
    int lenght = 0;
    for (int i = 0; i < sizeof(dim); i++) lenght *= dim[i];
    d.buffer = malloc(sizeof(int) * dataLenght);
    return d;
}

/**
 * @brief returns the index of the buffer for the given coordinates
 * @param {Array} coordinates array of numbers each number represents the coordinate of a dimension
 * @returns {number} index in the buffer
 */
int dimensions_getIndex(dimensions *d, unsigned int *coordinates) {
    int index = 0;
    for (int i = 0; i < d->dataLenght; i++) {
        int tmp = 1;
        for (int j = i + 1; j < d->dataLenght; j++) tmp *= d->dim[j];
        index += coordinates[i] * tmp;
    }
    return index;
}

/**
 * @brief returns the coordinates of the buffer for the given index
 * @param {number} index index in the buffer
 * @returns {Array} array of numbers each number represents the coordinate of a dimension
 */
unsigned int *dimensions_getCoordinates(dimensions *d, int index) {
    unsigned int *coordinates = malloc(sizeof(unsigned int) * d->dataLenght);
    for (int i = 0; i < d->dataLenght; i++) {
        int tmp = 1;
        for (int j = i + 1; j < d->dataLenght; j++) tmp *= d->dim[j];
        coordinates[i] = index / tmp;
        index -= coordinates[i] * tmp;
    }
    return coordinates;
}

/**
 * @brief returns the value of the buffer for the given coordinates
 * @param {Array} coordinates array of numbers each number represents the coordinate of a dimension
 * @returns {number} value in the buffer
 */
int dimensions_get(dimensions *d, unsigned int *coordinates) {
    return d->buffer[get_index(d, coordinates)];
}

/**
 * @brief sets the value of the buffer for the given coordinates
 * @param {Array} coordinates array of numbers each number represents the coordinate of a dimension
 * @param {number} value value in the buffer
 * @returns {number} value in the buffer
 */
int dimensions_set(dimensions *d, unsigned int *coordinates, int value) {
    return d->buffer[get_index(d, coordinates)] = value;
}

/**
 * @brief returns the value of the buffer for the given index
 * @param {number} index index in the buffer
 * @returns {number} value in the buffer
 */
int dimensions_getIndexValue(dimensions *d, int index) {
    return d->buffer[index];
}

/**
 * @brief sets the value of the buffer for the given index
 * @param {number} index index in the buffer
 * @param {number} value value in the buffer
 * @returns {number} value in the buffer
 */
int dimensions_setIndexValue(dimensions *d, int index, int value) {
    return d->buffer[index] = value;
}

/**
 * @brief fill data into tow coordinates
 * @param {Array} coordinates1 array of numbers each number represents the coordinate of a dimension
 * @param {Array} coordinates2 array of numbers each number represents the coordinate of a dimension
 * @param {number} value value in the buffer
 * @returns {number} value in the buffer
 */
int dimensions_fill(dimensions *d, unsigned int *coordinates1, unsigned int *coordinates2, int value) {
    for (int i = coordinates1[0]; i <= coordinates2[0]; i++) {
        for (int j = coordinates1[1]; j <= coordinates2[1]; j++) {
            for (int k = coordinates1[2]; k <= coordinates2[2]; k++) {
                unsigned int coordinates[3] = {i, j, k};
                set_value(d, coordinates, value);
            }
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
int *dimensions_gets(dimensions *d, unsigned int *coordinates1, unsigned int *coordinates2) {
    int *data = malloc(sizeof(int) * (coordinates2[0] - coordinates1[0] + 1) * (coordinates2[1] - coordinates1[1] + 1) * (coordinates2[2] - coordinates1[2] + 1));
    int index = 0;
    for (int i = coordinates1[0]; i <= coordinates2[0]; i++) {
        for (int j = coordinates1[1]; j <= coordinates2[1]; j++) {
            for (int k = coordinates1[2]; k <= coordinates2[2]; k++) {
                unsigned int coordinates[3] = {i, j, k};
                data[index++] = get_value(d, coordinates);
            }
        }
    }
    return data;
}

#ifdef __cplusplus
}
#endif