/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let chunkedArr = [];
    for(let i=0; i<arr.length; i+=size){
        chunkedArr.push(arr.slice(i, i+size));
    }
    return chunkedArr
    // if(size<=arr.size){
    //     return chunkedArr.push(arr);
    // } else {
    //     let tempArr = [];
    //     let count = 0;
    //     for(let i = 0; i<arr.length; i++){
    //         tempArr = [...tempArr, arr[i]];
    //         count++;
    //         if(count===size){
    //             chunkedArr.push(tempArr);
    //             tempArr = [];
    //             count = 0;
    //         }
    //     }
    //     if(tempArr.length>0){
    //             chunkedArr.push(tempArr)
    //         }
    //     return chunkedArr
    // }
};
