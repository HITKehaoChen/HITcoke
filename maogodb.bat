
          @echo off 
          echo 你好，欢迎使用mongodb启动批处理文件
          ::进入d盘，因为我的mongodb安装在D盘
          ::执行开启mongodb服务
          mongod   --dbpath "E:\MongoDB\data"
