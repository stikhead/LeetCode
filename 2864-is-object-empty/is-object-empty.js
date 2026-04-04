/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    let i = Object.keys(obj)
    return i.length===0 ? true : false
};