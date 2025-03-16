/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    const arr = s.split(" ");
    const words = arr.filter(elem=>elem != "");
    var res = ""
    words.forEach(word=>{
        res = word + " " + res
    })
    return res.substring(0,res.length - 1);
};