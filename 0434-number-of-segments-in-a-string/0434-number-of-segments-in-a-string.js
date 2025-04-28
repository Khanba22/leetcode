/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function (s) {
    const str = s.split(" ");
    var count = 0;
    str.forEach(i => {
        if (i !== "") {
            count++;
        }
    }
    )
    return count;

}