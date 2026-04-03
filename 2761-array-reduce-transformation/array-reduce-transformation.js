/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
// var reduce = function(nums, fn, init) {
//     let val = init;
//     nums.map((ele) => val = fn(val, ele ));
//     return val
// };

var reduce = function(nums, fn, init) {
    let val = init;

    for (const ele of nums) {
        val = fn(val, ele);
    }

    return val;
};