const std = @import("std");
const foo = @import("foo.zig");

pub fn main() !void {}

test "simple test" {
    var list = std.ArrayList(i32).init(std.testing.allocator);
    try list.append(42);
    try std.testing.expectEqual(42, list.pop());
}
