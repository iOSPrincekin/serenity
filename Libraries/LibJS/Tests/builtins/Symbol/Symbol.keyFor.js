// test("basic functionality", () => {
//   const localSym = Symbol("bar");
//   const globalSym = Symbol.for("bar");

//   expect(Symbol.keyFor(localSym)).toBeUndefined();
//   expect(Symbol.keyFor(globalSym)).toBe("bar");
// });

// test("bad argument values", () => {
//   [
//     [1, "1"],
//     [null, "null"],
//     [undefined, "undefined"],
//     [[], "[object Array]"],
//     [{}, "[object Object]"],
//     [true, "true"],
//     ["foobar", "foobar"],
//     [function () {}, "[object ScriptFunction]"], // FIXME: Better function stringification
//   ].forEach(testCase => {
//     expect(() => {
//       Symbol.keyFor(testCase[0]);
//     }).toThrowWithMessage(TypeError, `${testCase[1]} is not a symbol`);
//   });
// });
