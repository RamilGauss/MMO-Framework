print(_VERSION);

require('lfs');
require('LuaXml');
require('FillHeader');
require('FillSourceCPP');

-- Global value
add_include_in_header = {}
add_include_in_cpp    = {}

flgForceMake     = true;

fileCPP          = nil;
fileH            = nil;
name_packet      = nil;
id_packet        = nil;
full_name_packet = nil;
arr_stack_desc   = {};
size_stack_methods = 0;

path_name_xml    = "markup.xml";
destination_path = "";

--------------------------------------------------------
-- functions
-- create header
function create_header()
  fileH = nil
  local file_name = destination_path..name_packet..".h";
  local attr_file = lfs.attributes(file_name);
  if flgForceMake or attr_file==nil then
    fileH = io.open(file_name, "w+");
  end;
end;
--------------------------------------------------------
-- create source c++
function create_cpp()
  fileCPP = nil
  local file_name = destination_path..name_packet..".cpp";
  local attr_file = lfs.attributes(file_name);
  if flgForceMake or attr_file==nil then
    fileCPP = io.open(file_name, "w+");
  end;
end;
--------------------------------------------------------
function handle_desc(desc, node, flgRoot)
  if type(desc)~="table" then
    return;
  end;
 
  -- добавление нового стека
  local next_node = {};
  next_node["name"] = desc["name"];
  next_node["type"] = desc["type"];
  next_node["def_value"] = desc["def_value"];  
  if flgRoot==false then
    next_node["parent"] = node;
  end;
  node[#node+1] = next_node;
  
  for index_desc, value_desc in pairs(desc) do
    handle_desc(value_desc, next_node, false);
  end;
end;
--------------------------------------------------------
-- перебор всех описаний
function enum_child(tbl)
  for key, value in pairs(tbl) do
    if type(value)=="table" then
      handle_desc(value, arr_stack_desc, true);
    end;
  end;
end;
--------------------------------------------------------
-- каждый пакет в отдельности
function handle_packet(tbl)
  name_packet      = tbl["name"];
  id_packet        = tbl["id"];
  full_name_packet = tbl["full_name"];

  arr_stack_desc = {};
  enum_child(tbl);
  
  create_header();
  create_cpp(); 
  -- разбор иерархии
  if fileH~=nil and fileCPP~=nil then
    FillHeader();
    FillSourceCPP();
    print("Parse packet "..name_packet..".");
  else
    print("Packet "..name_packet.." is passed.");
  end;
end;
--------------------------------------------------------
function parse(tbl)
  for key, value in pairs(tbl) do
    if value=="packet" then
      handle_packet(tbl);
    end;
    if value=="include_header" then
      add_include_in_header[#add_include_in_header+1] = tbl["name"];
    end;
    if value=="include_cpp" then
      add_include_in_cpp[#add_include_in_cpp+1] = tbl["name"];
    end;
    if type(value)=="table" then 
      parse(value);
    end;
  end;
end;
--------------------------------------------------------
-- поиск ключей запуска
if #arg==0 then
  print("keys:");
  print("\"xml\"        - path_name_xml,");
  print("\"dst_path\" - destination path.");
  print("\"force\"    - force update files(true/false).");
  return;
end;

local tbl_arg = {};
local cnt = #arg/2;
for i=1,cnt do
  tbl_arg[arg[2*i-1]]=arg[2*i-0];
end;

if tbl_arg["xml"]~=nil then
  path_name_xml = tbl_arg["xml"];
end;

if tbl_arg["force"]~=nil then
  flgForceMake = tbl_arg["force"];
end;

if tbl_arg["dst_path"]~=nil then
  destination_path = tbl_arg["dst_path"];
end;
-- загрузка xml
local table_packet = xml.load(path_name_xml);
parse(table_packet);
--------------------------------------------------------