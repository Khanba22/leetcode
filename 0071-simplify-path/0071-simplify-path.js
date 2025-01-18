/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    const tokens = path.split("/");
    const stack = [];
    
    for (const token of tokens) {
        if (token === "." || token === "") {
            continue;
        } else if (token === "..") {
            if (stack.length > 0) stack.pop();
        } else {
            stack.push(token);
        }
    }
    
    return "/" + stack.join("/");
};
