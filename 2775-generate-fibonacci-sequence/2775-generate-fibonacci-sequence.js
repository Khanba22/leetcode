/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let z = 0;
    let o = 1;
    while(true){
        yield z;
        [z,o] = [o,z+o];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */