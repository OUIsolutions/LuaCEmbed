
import Build.CToolKit as ct
from Build.exemple_build import create_exemples
from Build.full_folder_zip import zip_folder
from platform import system as osname

STARTER = 'src/one.c'
TEST_NAME = 'LuaCEmbed_test.h'
OUTPUT_FULL = 'LuaCEmbed.h'

OUTPUT_TEST = 'tests/LuaCEmbed.h'

ct.generate_amalgamated_code(STARTER,OUTPUT_TEST)
use_valgrind = True

if osname() == 'Windows':
    use_valgrind = False


test = ct.FolderTestPreset(
    folder='tests/main_test',
    side_effect_folder='tests/target',
    use_valgrind=use_valgrind
    )

test.generate_ouptut(reconstruct=False)
test.start_test()
create_exemples(TEST_NAME,OUTPUT_FULL)

ct.include_code_in_markdown('README.md',save_file=True)
ct.generate_amalgamated_code(STARTER,OUTPUT_FULL)
