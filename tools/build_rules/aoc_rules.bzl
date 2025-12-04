def make_day(name, data):
    native.cc_binary(
        name = name,
        srcs = [name + ".cpp"],
        data = data,
    )