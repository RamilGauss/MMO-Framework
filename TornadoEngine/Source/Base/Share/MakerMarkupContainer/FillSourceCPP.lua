function WriteLineCPP()
  fileCPP:write("//---------------------------------------------------------\n");
end;
---------------------------------------------------------------------
function WriteFormula(node)
  -- формула
  if #node==0 then
    fileCPP:write(" C ");
  else
    fileCPP:write(" Arr( ");
  end;
  
  for index, value in pairs(node) do
    if type(value)=="table" and index~="parent" then
      WriteFormula(value);
    end;
  end;
  
  if #node>0 then 
    fileCPP:write(" ) ");
  end;
end;
---------------------------------------------------------------------
function WriteGlobalStr(node)
  local name = node["name"];
  if name~=nil then
    fileCPP:write("  const char* g_p"..name.." = \""..name.."\";\n");
  end;
    
  for index, value in pairs(node) do
    if type(value)=="table" and index~="parent" then
      WriteGlobalStr(value);
    end;
  end;
end;
---------------------------------------------------------------------
function WritePushDesc(node, num_tab)
  
  local str_tab_pre = "";
  local str_tab     = "  ";
  for i_tab = 1, num_tab do
    str_tab     = str_tab.."  ";
    str_tab_pre = str_tab_pre.."  ";
  end;
  
  local name      = node["name"];
  local type_node = node["type"];
  if name~=nil and type_node~=nil then
    fileCPP:write(str_tab);
    fileCPP:write("IMarkUpContainer::TDesc* p"..name.." = new IMarkUpContainer::TDesc;\n");
    fileCPP:write(str_tab);
    fileCPP:write("p"..name.."->name = g_p"..name..";\n");
    fileCPP:write(str_tab);
    fileCPP:write("p"..name.."->size = sizeof("..type_node..");\n");
    for index, value in pairs(node) do
      if type(value)=="table" and index~="parent" then
        WritePushDesc(value, num_tab + 1);
      end;
    end;
    local parent = node["parent"];
    if parent==nil then
      fileCPP:write(str_tab_pre);
      fileCPP:write("mRootDesc->list.push_back(p"..name..");\n");
      fileCPP:write("\n");
    else
      local name_parent = parent["name"];
      fileCPP:write(str_tab_pre);
      fileCPP:write("p"..name_parent.."->list.push_back(p"..name..");\n");
    end;
  end;
end;
---------------------------------------------------------------------
function WriteBody_GET_N(name, type_param, arr_name, i)
  local tabs = "";
  for i_tab = 1,i do
    tabs = "  "..tabs;
  end;
  
  local name_index = arr_name[#arr_name - i + 1];
  if name_index~=nil then
    fileCPP:write(tabs);
    fileCPP:write("if(mMarkUp->Enter(g_p"..name_index..", index"..name_index.." ))\n");
    
    fileCPP:write(tabs);
    fileCPP:write("{\n");
    
    WriteBody_GET_N(name, type_param, arr_name, i + 1);
    
    fileCPP:write(tabs);
    fileCPP:write("}\n");
    
  else
    fileCPP:write(tabs);
    fileCPP:write(type_param.."* p = ("..type_param.."*)mMarkUp->GetPtrConst(g_p"..name..");\n");
    
    -- проверка результата
    fileCPP:write(tabs)fileCPP:write("if(p==NULL)\n");
    fileCPP:write(tabs)fileCPP:write("{\n");
    fileCPP:write(tabs)fileCPP:write("  BL_FIX_BUG();\n");
    fileCPP:write(tabs)fileCPP:write("  return "..type_param.."();\n");
    fileCPP:write(tabs)fileCPP:write("}\n");
    
    fileCPP:write(tabs);
    fileCPP:write(type_param.." res = *p;\n");
    
    fileCPP:write(tabs);
    fileCPP:write("return res;\n");
  end;
end;
---------------------------------------------------------------------
function WriteBody_GET(name, type_param, arr_name)
  fileCPP:write("{\n");
  fileCPP:write("  mMarkUp->EnterRoot();\n");
  
  WriteBody_GET_N(name, type_param, arr_name, 1);
  
  if #arr_name>0 then
    fileCPP:write("  return "..type_param.."();\n");
  end
  fileCPP:write("}\n");
  WriteLineCPP();
end
---------------------------------------------------------------------
function WriteBody_GET_COUNT_N(name, type_param, arr_name, i)
  local tabs = "";
  for i_tab = 1,i do
    tabs = "  "..tabs;
  end;
  
  local name_index = arr_name[#arr_name - i + 1];
  if name_index~=nil then
    fileCPP:write(tabs);
    fileCPP:write("if(mMarkUp->Enter(g_p"..name_index..", index"..name_index.." ))\n");
    
    fileCPP:write(tabs);
    fileCPP:write("{\n");
    
    WriteBody_GET_COUNT_N(name, type_param, arr_name, i + 1);
    
    fileCPP:write(tabs);
    fileCPP:write("}\n");
    
  else
    fileCPP:write(tabs);
    fileCPP:write("int cnt = mMarkUp->GetCount(g_p"..name..");\n");
   
    fileCPP:write(tabs);
    fileCPP:write("return cnt;\n");
  end;
end;
---------------------------------------------------------------------
function WriteBody_GET_COUNT(name, type_param, arr_name)
  fileCPP:write("{\n");
  fileCPP:write("  mMarkUp->EnterRoot();\n");
  
  WriteBody_GET_COUNT_N(name, type_param, arr_name, 1);
  
  if #arr_name>0 then
    fileCPP:write("  return 0;\n");
  end;
  
  fileCPP:write("}\n");
  WriteLineCPP();
end
---------------------------------------------------------------------
function WriteBody_SET_N(name, type_param, arr_name, i)
  local tabs = "";
  for i_tab = 1,i do
    tabs = "  "..tabs;
  end;
  
  local name_index = arr_name[#arr_name - i + 1];
  if name_index~=nil then
    fileCPP:write(tabs);
    fileCPP:write("if(mMarkUp->Enter(g_p"..name_index..", index"..name_index.." ))\n");
    
    fileCPP:write(tabs);
    fileCPP:write("{\n");
    
    WriteBody_SET_N(name, type_param, arr_name, i + 1);
    
    fileCPP:write(tabs);
    fileCPP:write("}\n");
    
  else
    fileCPP:write(tabs);
    fileCPP:write(type_param.."* p = ("..type_param.."*)mMarkUp->GetPtrConst(g_p"..name..");\n");
    
    -- проверка результата
    fileCPP:write(tabs) fileCPP:write("if(p==NULL)\n");
    fileCPP:write(tabs) fileCPP:write("{\n");
    fileCPP:write(tabs) fileCPP:write("  BL_FIX_BUG();\n");
    fileCPP:write(tabs) fileCPP:write("  return;\n");
    fileCPP:write(tabs) fileCPP:write("}\n");
    
    fileCPP:write(tabs) fileCPP:write("*p = v;\n");
  end
end
---------------------------------------------------------------------
function WriteBody_SET(name, type_param, arr_name)
  fileCPP:write("{\n");
  fileCPP:write("  mMarkUp->EnterRoot();\n");
  
  WriteBody_SET_N(name, type_param, arr_name, 1);
  
  fileCPP:write("}\n");
  WriteLineCPP();
end;
---------------------------------------------------------------------
function WriteBody_SET_COUNT_N(name, type_param, arr_name, i)
  local tabs = "";
  for i_tab = 1,i do
    tabs = "  "..tabs;
  end;
  
  local name_index = arr_name[#arr_name - i + 1];
  if name_index~=nil then
    fileCPP:write(tabs);
    fileCPP:write("if(mMarkUp->Enter(g_p"..name_index..", index"..name_index.." ))\n");
    
    fileCPP:write(tabs);
    fileCPP:write("{\n");
    
    WriteBody_SET_COUNT_N(name, type_param, arr_name, i + 1);
    
    fileCPP:write(tabs);
    fileCPP:write("}\n");
  else
    fileCPP:write(tabs);
    fileCPP:write("mMarkUp->SetCount(g_p"..name..", v);\n");
  end
end
---------------------------------------------------------------------
function WriteBody_SET_COUNT(name, type_param, arr_name)
  fileCPP:write("{\n");
  fileCPP:write("  mMarkUp->EnterRoot();\n");
  
  WriteBody_SET_COUNT_N(name, type_param, arr_name, 1);
    
  fileCPP:write("}\n");
  WriteLineCPP();
end
---------------------------------------------------------------------
function WriteSetDefValue()
  for index, value in pairs(arr_stack_desc) do
    local name = value["name"];
    local def_value = value["def_value"];
    if def_value~=nil then
      fileCPP:write("  Set"..name.."("..def_value..");\n");
    end
  end;
end;
---------------------------------------------------------------------
function WriteMethodBodyByNode(node)
  size_stack_methods = size_stack_methods + 1;
  local arr_name = {};
  -- формирование методов
  local name_node = node["name"];
  local type_node = node["type"];
  local cnt_child = #node;
  ---------------------------------
  local str_index_param = "";
  local parent = node["parent"];
  for i=1,size_stack_methods do
    if parent==nil then
      break;
    end;
    local name_parent = parent["name"];
    if #str_index_param==0 then
      str_index_param = "int index"..name_parent;
    else
      str_index_param = "int index"..name_parent..", "..str_index_param;
    end
    parent = parent["parent"];
    
    arr_name[i] = name_parent;
  end
  ---------------------------------
  if cnt_child==0 then -- Const
    fileCPP:write(type_node.." T"..name_packet.."::Get"..name_node.."("..str_index_param..")\n");
    WriteBody_GET(name_node, type_node, arr_name); -- тело метода
    if #str_index_param~=0 then
      str_index_param = str_index_param..", ";
    end;
    fileCPP:write("void T"..name_packet.."::Set"..name_node.."("..str_index_param..type_node.." v)\n");
    WriteBody_SET(name_node, type_node, arr_name); -- тело метода
  else -- Arr
    fileCPP:write("int T"..name_packet.."::GetCount"..name_node.."("..str_index_param..")\n");
    WriteBody_GET_COUNT(name_node, type_node, arr_name); -- тело метода
    if #str_index_param~=0 then
      str_index_param = str_index_param..", ";
    end;
    fileCPP:write("void T"..name_packet.."::SetCount"..name_node.."("..str_index_param.."int v)\n");
    WriteBody_SET_COUNT(name_node, type_node, arr_name); -- тело метода
  end;
  ---------------------------------
  for index, value in pairs(node) do
    if type(value)=="table" and index~="parent" then
      WriteMethodBodyByNode(value);
    end;
  end;
  size_stack_methods = size_stack_methods - 1;
end;
---------------------------------------------------------------------
function FillSourceCPP()
  fileCPP:write("#include \""..name_packet..".h\"\n");
  
  for index_add_include, str_include in pairs(add_include_in_cpp) do
    fileCPP:write("#include \""..str_include.."\"\n");
  end;
  
  fileCPP:write("\n");
  ------------------------------------------
  -- типа: формула пакета Root(C, Arr(C), C)
  fileCPP:write("// формула пакета Root(");
  for index_node, node in pairs(arr_stack_desc) do
    WriteFormula(node);
  end;
  fileCPP:write(")\n");
  fileCPP:write("\n");
  ------------------------------------------  
  -- namespace пакета
  fileCPP:write("namespace ns"..name_packet.."\n");
  fileCPP:write("{\n");
  for index_node, node in pairs(arr_stack_desc) do
    WriteGlobalStr(node);
  end;
  fileCPP:write("}\n");
  ------------------------------------------
  fileCPP:write("\n");
  fileCPP:write("using namespace std;\n");
  fileCPP:write("using namespace ns"..name_packet..";\n");
  fileCPP:write("\n");
  fileCPP:write("T"..name_packet.."::T"..name_packet.."()\n");
  fileCPP:write("{\n");
  -- вставка иерархии в MarkUp
  -----------------------------
  for index_node, node in pairs(arr_stack_desc) do
    WritePushDesc(node, 1);
  end;
  fileCPP:write("  mMarkUp->SetMarkUp(mRootDesc);\n");
  fileCPP:write("\n");  
  fileCPP:write("  SetDefValue();\n");
  -----------------------------
  fileCPP:write("}\n");
  WriteLineCPP();
  fileCPP:write("T"..name_packet.."::~T"..name_packet.."()\n");
  fileCPP:write("{\n");
  fileCPP:write("\n");
  fileCPP:write("}\n");
  WriteLineCPP();
  fileCPP:write("void T"..name_packet.."::SetDefValue()\n");
  fileCPP:write("{\n");
  WriteSetDefValue();
  fileCPP:write("}\n");
  WriteLineCPP();
  fileCPP:write("int  T"..name_packet.."::GetID()\n");
  fileCPP:write("{\n");
  fileCPP:write("  return "..id_packet..";\n");
  fileCPP:write("}\n");
  WriteLineCPP();  
  fileCPP:write("std::string T"..name_packet.."::GetName()\n");
  fileCPP:write("{\n");
  fileCPP:write("  return \""..full_name_packet.."\";\n");
  fileCPP:write("}\n");
  WriteLineCPP();  
  -- перебор методов
  for index_node, node in pairs(arr_stack_desc) do
    WriteMethodBodyByNode(node);
  end;
  
  fileCPP:flush();
  fileCPP:close();
end;
---------------------------------------------------------------------
