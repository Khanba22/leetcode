/**
 * @param {string} path
 * @return {string}
 */
var simplifyPath = function(path) {
    var tokens = path.split("/");
    tokens = tokens.filter(string=>string != "");
    console.log(tokens);
    var res = "";
    var str = []
    for(var i = 0;i < tokens.length;i++){
        const token = tokens[i];
        if(token == '.'){
            continue;
        }
        else if(token == ".."){
            str.pop();
        }else{
            str.push(token)
        };
    }
    return "/" + str.join("/");
};