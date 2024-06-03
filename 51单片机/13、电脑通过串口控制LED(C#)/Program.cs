
using System;
using System.IO.Ports;

namespace _13_电脑通过串口控制LED_C__
{
    class Program
    {
        static SerialPort serialPort;

        static void Main(string[] args)
        {
            //首先烧录12、电脑通过串口控制led灯的代码，C#代码通过串口发送数据和传输数据
            // 设置串口参数
            serialPort = new SerialPort("COM3", 4800, Parity.None, 8, StopBits.One);

            // 注册事件处理程序
            serialPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

            // 打开串口
            serialPort.Open();
            while (true)
            {
                Console.WriteLine("请输入0~255的范围");
                var ins=  Console.ReadLine();
                if (ins=="q")
                {
                    break;
                }
                //发送一个字节控制八个led，一个字节八位，一位控制一个LED，0~255转成二进制，0对应的亮，1对应的灭。
                // 发送数据
                Console.WriteLine($"二进制："+ Convert.ToString(Convert.ToByte(ins),2).PadLeft(8,'0'));
                serialPort.Write(new byte[] { Convert.ToByte(ins) }, 0, 1);
            }
            

            // 等待用户关闭程序
            Console.WriteLine("Press any key to exit...");
            Console.ReadKey();

            // 关闭串口
            serialPort.Close();
        }

        // 数据接收事件处理程序
        static void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            var indata = sp.ReadByte();
            Console.Write("Data Received:");
            Console.WriteLine(indata);
        }
    }
}

 