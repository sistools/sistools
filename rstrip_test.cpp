
/* *********************************************************
 * includes
 */

#include "rstrip.h"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <xtests/util/temp_file.hpp>

#include <platformstl/filesystem/file_lines.hpp>
#include <platformstl/filesystem/FILE_stream.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>

#include <stdio.h>


/* *********************************************************
 * types
 */

using ::xtests::cpp::util::temp_file;


/* *********************************************************
 * compatibility
 */

#if 0
#elif PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_MAJOR > 2 || \
      (  PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_MAJOR == 2 && \
         PLATFORMSTL_VER_PLATFORMSTL_FILESYSTEM_HPP_FILE_STREAM_MINOR >= 2)

# define FILE_stream_HAS_read_all
#endif


/* *********************************************************
 * tests
 */

SCENARIO("empty-input") {

    GIVEN("an empty input file") {

        temp_file   tf_in(temp_file::EmptyOnOpen | temp_file::DeleteOnClose);
        temp_file   tf_out(temp_file::EmptyOnOpen | temp_file::DeleteOnClose | temp_file::CloseOnOpen);

        {
            FILE*   in  =   fopen(tf_in.c_str(), "r");
            FILE*   out =   fopen(tf_out.c_str(), "w");

            stlsoft::scoped_handle<FILE*>   scoper_in(in, fclose);
            stlsoft::scoped_handle<FILE*>   scoper_out(out, fclose);

            int r = sistool_rstrip(in, out, 0);

            REQUIRE(0 == r);
        }

        platformstl::file_lines out_lines(tf_out);

        CHECK(0 == out_lines.size());
    }

    GIVEN("an input file with a single unterminated line") {

        static char const input[] = "abc";

        temp_file   tf_in(temp_file::EmptyOnOpen | temp_file::DeleteOnClose, input, strlen(input));
        temp_file   tf_out(temp_file::EmptyOnOpen | temp_file::DeleteOnClose | temp_file::CloseOnOpen);

        {
            FILE*   in  =   fopen(tf_in.c_str(), "r");
            FILE*   out =   fopen(tf_out.c_str(), "w");

            stlsoft::scoped_handle<FILE*>   scoper_in(in, fclose);
            stlsoft::scoped_handle<FILE*>   scoper_out(out, fclose);

            int r = sistool_rstrip(in, out, 0);

            REQUIRE(0 == r);
        }

        platformstl::file_lines out_lines(tf_out);

        REQUIRE(1 == out_lines.size());
        CHECK("abc" == out_lines[0]);

#if FILE_stream_HAS_read_all

        platformstl::FILE_stream out_stm(tf_out, "r");
        auto const out_contents = out_stm.read_all<std::string>();

        CHECK("abc" == out_contents);
#endif
    }

    GIVEN("an input file with a single unterminated line with trailing space") {

        static char const input[] = "abc ";

        temp_file   tf_in(temp_file::EmptyOnOpen | temp_file::DeleteOnClose, input, strlen(input));
        temp_file   tf_out(temp_file::EmptyOnOpen | temp_file::DeleteOnClose | temp_file::CloseOnOpen);

        {
            FILE*   in  =   fopen(tf_in.c_str(), "r");
            FILE*   out =   fopen(tf_out.c_str(), "w");

            stlsoft::scoped_handle<FILE*>   scoper_in(in, fclose);
            stlsoft::scoped_handle<FILE*>   scoper_out(out, fclose);

            int r = sistool_rstrip(in, out, 0);

            REQUIRE(0 == r);
        }

        platformstl::file_lines out_lines(tf_out);

        REQUIRE(1 == out_lines.size());
        CHECK("abc" == out_lines[0]);

#if FILE_stream_HAS_read_all

        platformstl::FILE_stream out_stm(tf_out, "r");
        auto const out_contents = out_stm.read_all<std::string>();

        CHECK("abc" == out_contents);
#endif
    }

    GIVEN("an input file with a single unterminated line with trailing spaces") {

        static char const input[] = "abc  ";

        temp_file   tf_in(temp_file::EmptyOnOpen | temp_file::DeleteOnClose, input, strlen(input));
        temp_file   tf_out(temp_file::EmptyOnOpen | temp_file::DeleteOnClose | temp_file::CloseOnOpen);

        {
            FILE*   in  =   fopen(tf_in.c_str(), "r");
            FILE*   out =   fopen(tf_out.c_str(), "w");

            stlsoft::scoped_handle<FILE*>   scoper_in(in, fclose);
            stlsoft::scoped_handle<FILE*>   scoper_out(out, fclose);

            int r = sistool_rstrip(in, out, 0);

            REQUIRE(0 == r);
        }

        platformstl::file_lines out_lines(tf_out);

        REQUIRE(1 == out_lines.size());
        CHECK("abc" == out_lines[0]);

#if FILE_stream_HAS_read_all

        platformstl::FILE_stream out_stm(tf_out, "r");
        auto const out_contents = out_stm.read_all<std::string>();

        CHECK("abc" == out_contents);
#endif
    }

    GIVEN("an input file with a single unterminated line with trailing TAB") {

        static char const input[] = "abc\t";

        temp_file   tf_in(temp_file::EmptyOnOpen | temp_file::DeleteOnClose, input, strlen(input));
        temp_file   tf_out(temp_file::EmptyOnOpen | temp_file::DeleteOnClose | temp_file::CloseOnOpen);

        {
            FILE*   in  =   fopen(tf_in.c_str(), "r");
            FILE*   out =   fopen(tf_out.c_str(), "w");

            stlsoft::scoped_handle<FILE*>   scoper_in(in, fclose);
            stlsoft::scoped_handle<FILE*>   scoper_out(out, fclose);

            int r = sistool_rstrip(in, out, 0);

            REQUIRE(0 == r);
        }

        platformstl::file_lines out_lines(tf_out);

        REQUIRE(1 == out_lines.size());
        CHECK("abc" == out_lines[0]);

#if FILE_stream_HAS_read_all

        platformstl::FILE_stream out_stm(tf_out, "r");
        auto const out_contents = out_stm.read_all<std::string>();

        CHECK("abc" == out_contents);
#endif
    }

    GIVEN("an input file with a single unterminated line with trailing TABs") {

        static char const input[] = "abc\t\t";

        temp_file   tf_in(temp_file::EmptyOnOpen | temp_file::DeleteOnClose, input, strlen(input));
        temp_file   tf_out(temp_file::EmptyOnOpen | temp_file::DeleteOnClose | temp_file::CloseOnOpen);

        {
            FILE*   in  =   fopen(tf_in.c_str(), "r");
            FILE*   out =   fopen(tf_out.c_str(), "w");

            stlsoft::scoped_handle<FILE*>   scoper_in(in, fclose);
            stlsoft::scoped_handle<FILE*>   scoper_out(out, fclose);

            int r = sistool_rstrip(in, out, 0);

            REQUIRE(0 == r);
        }

        platformstl::file_lines out_lines(tf_out);

        REQUIRE(1 == out_lines.size());
        CHECK("abc" == out_lines[0]);

#if FILE_stream_HAS_read_all

        platformstl::FILE_stream out_stm(tf_out, "r");
        auto const out_contents = out_stm.read_all<std::string>();

        CHECK("abc" == out_contents);
#endif
    }

    GIVEN("an input file with a single unterminated line with trailing space") {

        static char const input[] = "abc ";

        temp_file   tf_in(temp_file::EmptyOnOpen | temp_file::DeleteOnClose, input, strlen(input));
        temp_file   tf_out(temp_file::EmptyOnOpen | temp_file::DeleteOnClose | temp_file::CloseOnOpen);

        {
            FILE*   in  =   fopen(tf_in.c_str(), "r");
            FILE*   out =   fopen(tf_out.c_str(), "w");

            stlsoft::scoped_handle<FILE*>   scoper_in(in, fclose);
            stlsoft::scoped_handle<FILE*>   scoper_out(out, fclose);

            int r = sistool_rstrip(in, out, 0);

            REQUIRE(0 == r);
        }

        platformstl::file_lines out_lines(tf_out);

        REQUIRE(1 == out_lines.size());
        CHECK("abc" == out_lines[0]);

#if FILE_stream_HAS_read_all

        platformstl::FILE_stream out_stm(tf_out, "r");
        auto const out_contents = out_stm.read_all<std::string>();

        CHECK("abc" == out_contents);
#endif
    }

    GIVEN("an input file with a single unterminated line with trailing spaces") {

        static char const input[] = "abc  ";

        temp_file   tf_in(temp_file::EmptyOnOpen | temp_file::DeleteOnClose, input, strlen(input));
        temp_file   tf_out(temp_file::EmptyOnOpen | temp_file::DeleteOnClose | temp_file::CloseOnOpen);

        {
            FILE*   in  =   fopen(tf_in.c_str(), "r");
            FILE*   out =   fopen(tf_out.c_str(), "w");

            stlsoft::scoped_handle<FILE*>   scoper_in(in, fclose);
            stlsoft::scoped_handle<FILE*>   scoper_out(out, fclose);

            int r = sistool_rstrip(in, out, 0);

            REQUIRE(0 == r);
        }

        platformstl::file_lines out_lines(tf_out);

        REQUIRE(1 == out_lines.size());
        CHECK("abc" == out_lines[0]);

#if FILE_stream_HAS_read_all

        platformstl::FILE_stream out_stm(tf_out, "r");
        auto const out_contents = out_stm.read_all<std::string>();

        CHECK("abc" == out_contents);
#endif
    }

    GIVEN("an input file with a single line and a trailing EOL") {

        static char const input[] = "abc\n";

        temp_file   tf_in(temp_file::EmptyOnOpen | temp_file::DeleteOnClose, input, strlen(input));
        temp_file   tf_out(temp_file::EmptyOnOpen | temp_file::DeleteOnClose | temp_file::CloseOnOpen);

        {
            FILE*   in  =   fopen(tf_in.c_str(), "r");
            FILE*   out =   fopen(tf_out.c_str(), "w");

            stlsoft::scoped_handle<FILE*>   scoper_in(in, fclose);
            stlsoft::scoped_handle<FILE*>   scoper_out(out, fclose);

            int r = sistool_rstrip(in, out, 0);

            REQUIRE(0 == r);
        }

        platformstl::file_lines out_lines(tf_out);

        REQUIRE(1 == out_lines.size());
        CHECK("abc" == out_lines[0]);

#if FILE_stream_HAS_read_all

        platformstl::FILE_stream out_stm(tf_out, "r");
        auto const out_contents = out_stm.read_all<std::string>();

        CHECK("abc\n" == out_contents);
#endif
    }

    GIVEN("an input file with five lines with various whitespace") {

        static char const input[] = "abc\nabc \n\t\n abc\n\t abc\t ";

        temp_file   tf_in(temp_file::EmptyOnOpen | temp_file::DeleteOnClose, input, strlen(input));
        temp_file   tf_out(temp_file::EmptyOnOpen | temp_file::DeleteOnClose | temp_file::CloseOnOpen);

        {
            FILE*   in  =   fopen(tf_in.c_str(), "r");
            FILE*   out =   fopen(tf_out.c_str(), "w");

            stlsoft::scoped_handle<FILE*>   scoper_in(in, fclose);
            stlsoft::scoped_handle<FILE*>   scoper_out(out, fclose);

            int r = sistool_rstrip(in, out, 0);

            REQUIRE(0 == r);
        }

        platformstl::file_lines out_lines(tf_out);

        REQUIRE(5 == out_lines.size());
        CHECK("abc" == out_lines[0]);
        CHECK("abc" == out_lines[1]);
        CHECK("" == out_lines[2]);
        CHECK(" abc" == out_lines[3]);
        CHECK("\t abc" == out_lines[4]);

#if FILE_stream_HAS_read_all

        platformstl::FILE_stream out_stm(tf_out, "r");
        auto const out_contents = out_stm.read_all<std::string>();

        CHECK("abc\nabc\n\n abc\n\t abc" == out_contents);
#endif
    }
}


/* ///////////////////// end of file //////////////////// */

