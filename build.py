
import Build.CToolKit as ct
from Build.exemple_build import create_exemples
from Build.full_folder_zip import zip_folder


STARTER = 'src/one.c'

OUTPUT = 'LuaCEmbed.h'


ct.generate_amalgamated_code(STARTER,OUTPUT)

ct.include_code_in_markdown('README.md',save_file=True)


