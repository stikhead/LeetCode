/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    for (const key in obj) {
        return false;
    }
    return true;
    // let i = Object.keys(obj)
    // return i.length===0 ? true : false
};