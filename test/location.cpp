#include <fmt/core.h>
#include <source_location>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    auto path = fs::path(argv[0]);
    fmt::print("{}\n", path.parent_path().string());
    return 0;
}
