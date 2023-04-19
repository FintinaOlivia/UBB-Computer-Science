import sys
sys.path.insert(0, 'src/inbound')

import repositoryJson
import repositoryText
import repositoryPickle
#from outbound import OUTsql

def push_db(array:list):
    database = {}
    with open('src/settings.properties') as file:
        for line in file:
            if line[0]!='[':
                key, value = line.split('=')
                database[key] = value
        
    if database['database_name'] == 'json\n':
        #OUTjson.pushing(array)
        repositoryJson.pushing(array)

    elif database['database_name'] == 'txt\n':
        #OUTtxt.pushing(array)
        repositoryText.pushing(array)

    elif database['database_name'] == 'pickle\n':
        #OUTpickle.pushing(array)
        repositoryPickle.pushing(array)
        
        
    """elif database['dbname']=='sql\n':
        OUTsql.pushing(array, modifications)
        mods=[]"""