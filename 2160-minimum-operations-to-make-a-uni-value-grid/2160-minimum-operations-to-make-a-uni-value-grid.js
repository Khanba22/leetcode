/**
 * @param {number[][]} grid
 * @param {number} x
 * @return {number}
 */
var minOperations = function(grid, x) {
    const arr = grid.flat();
    arr.sort((a, b) => a - b);
    
    const mid = arr[Math.floor(arr.length / 2)];
    let oper = 0;
    
    for (let elem of arr) {
        if ((mid - elem) % x !== 0) {
            return -1;
        }
        oper += Math.abs(mid - elem) / x;
    }
    
    return oper;
};
