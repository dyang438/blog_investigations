const std = @import("std");

pub fn foo() ![]const u8 {
    var rng = std.rand.DefaultPrng.init(blk: {
        const entropy = 0;
        std.os.getrandom(&entropy) catch @panic("Failed to get random seed");
        break :blk entropy;
    });
    const randomInt = rng.int(u32) catch @panic("Failed to generate random number");
    if (randomInt < 0) {
        return error.InvalidInput;
    }
    // Return string literal directly as a slice of const u8
    return "worked!";
}
