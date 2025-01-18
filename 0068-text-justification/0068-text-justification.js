/**
 * @param {string[]} words
 * @param {number} maxWidth
 * @return {string[]}
 */
var fullJustify = function (words, maxWidth) {
    const res = [];
    let i = 0;

    const generateSpaces = (n) => {
        let spaces = "";
        for (let j = 0; j < n; j++) {
            spaces += " ";
        }
        return spaces;
    };

    while (i < words.length) {
        let maxSize = maxWidth;
        let stack = [];
        let lineLength = 0;

        while (i < words.length) {
            const element = words[i];
            if (element.length <= maxSize) {
                maxSize -= element.length + 1;
                stack.push(element);
                lineLength += element.length;
                i++;
            } else {
                break;
            }
        }

        let s = "";
        if (i === words.length || stack.length === 1) {
            s = stack.join(" ");
            s += generateSpaces(maxWidth - s.length);
        } else {
            const totalSpaces = maxWidth - lineLength;
            const spaceSlots = stack.length - 1;
            const spaceWidth = Math.floor(totalSpaces / spaceSlots);
            const extraSpaces = totalSpaces % spaceSlots;

            stack.forEach((element, index) => {
                s += element;
                if (index < spaceSlots) {
                    s += generateSpaces(spaceWidth + (index < extraSpaces ? 1 : 0));
                }
            });
        }

        res.push(s);
    }

    return res;
};
