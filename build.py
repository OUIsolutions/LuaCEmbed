
import Build.CToolKit as ct
from Build.exemple_build import create_exemples
from Build.full_folder_zip import zip_folder


STARTER = 'src/one.c'

OUTPUT = 'LuaCEmbed.h'


result = ct.generate_amalgamated_code(STARTER)

with open(OUTPUT,'w') as arq:
    arq.write(result)
    
ct.include_code_in_markdown('README.md',save_file=True)


