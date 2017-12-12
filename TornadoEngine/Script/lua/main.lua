-- where is json file markup
local jsonPath = "..\\..\\Test\\Marshallizator\\markup.json";
-- destination 
local dstPath  = "..\\..\\Test\\Marshallizator\\";
-- 
local generator = require('generatorSerializable');
generator.generate( jsonPath, dstPath );
