class Solution {
    numFactoredBinaryTrees(arr) {
        const mp = new Map();
        const n = arr.length;
        arr.sort((a, b) => a - b);

        for (let i = 0; i < n; i++) {
            mp.set(arr[i], 1);
        }

        for (let i = 0; i < n; i++) {
            const root = arr[i];
            for (let j = 0; j < i; j++) {
                if (root % arr[j] === 0 && mp.has(root / arr[j])) {
                    mp.set(root, (mp.get(arr[j]) * mp.get(root / arr[j])) % 1000000007);
                }
            }
        }

        let ans = 0;
        for (const [key, value] of mp.entries()) {
            ans = (ans + value) % 1000000007;
        }

        return ans;
    }
}

function main() {
    const solution = new Solution();
    const arr = [2, 4, 5, 10];
    const result = solution.numFactoredBinaryTrees(arr);

    console.log("Result: " + result);
}

main();
