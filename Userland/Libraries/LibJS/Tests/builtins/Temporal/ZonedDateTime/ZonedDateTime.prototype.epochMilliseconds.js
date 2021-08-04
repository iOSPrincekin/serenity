describe("correct behavior", () => {
    test("basic functionality", () => {
        const timeZone = new Temporal.TimeZone("UTC");
        const zonedDateTime = new Temporal.ZonedDateTime(1625614921000000000n, timeZone);
        expect(zonedDateTime.epochMilliseconds).toBe(1625614921000);
    });
});

test("errors", () => {
    test("this value must be a Temporal.ZonedDateTime object", () => {
        expect(() => {
            Reflect.get(Temporal.ZonedDateTime.prototype, "epochMilliseconds", "foo");
        }).toThrowWithMessage(TypeError, "Not a Temporal.ZonedDateTime");
    });
});
