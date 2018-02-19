var mysql = require('mysql');
var pool = mysql.createPool({
  connectionLimit : 10,
  host            : 'classmysql.engr.oregonstate.edu',
  user            : 'cs290_edwardrh',
  password        : '9303',
  database        : 'cs290_edwardrh'
});

module.exports.pool = pool;
