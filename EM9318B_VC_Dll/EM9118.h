//��DLL��Ҫ�ṩ������������EM9118����
/*�������ʱ���÷�����
�ڲɼ���ʼ���һ�ε���EM9118_ExtractADCode֮ǰ����Ҫ����EM9118_Init������Ȼ����ֹͣ�ɼ�֮ǰ�������ٴε���EM9118_Init
ÿ�ε���EM9118_ExtractADCode����������������Ϊÿ��ͨ������һ��ԭ�����飬����������ͨ��EM9118_GetADChCode������
����ڵ���EM9118_ExtractADCode��û��ͨ��EM9118_GetADChCode���������ݣ�����һ�ε���EM9118_ExtractADCode�󽫻ᱻ����
*/

#ifndef EM9118_H
#define EM9118_H

#define EM9118_TIMOUT_MS                            1000
#define EM9118_USB_MAX_COUNT                        16 //����֧��USBģ�����
#define EM9118_BASE_FREQ                            36000000.0//����ʱ�ӣ�36M
#define EM9118_PWM_BASE_FREQ                        4000000.0//PWM��׼��Ƶϵ��
#define EM9118_MAXADCHCNT                           18 //AD���ͨ����
#define EM9118_MAXDOCHCNT                           2 //DO���ͨ����
#define EM9118_MAXDICHCNT                           4 //DI���ͨ����
#define EM9118_MAXCTCHCNT                           4 //���������ͨ����
#define EM9118_MAXECCHCNT                           2 //���������ͨ����
#define EM9118_MAXPWMCHCNT                          2 //PWM���ͨ����
#define EM9106_MAXIOCHCNT							24//EM9106��IO���ͨ����
#define EM9318_MAXIOCHCNT							8 //EM9318��IO���ͨ����
#define EM9318_MAXPWMCHCNT                          4 //EM9318��PWM���ͨ����
#define EM9318_MAXECCHCNT                           2 //EM9318�ı��������ͨ����
#define EM9318_PWM_BASE_FREQ                        36000000.0//EM9318��PWMʱ��Ƶ�ʣ�36M

//������ʽ
#define EM9118_CLKSRC_IN                            0 //��ʱ�������ɼ�
#define EM9118_CLKSRC_EX                            1 //��ʱ�������ɼ�
#define EM9118_TRISRC_IN                            0 //�ڴ��������ɼ�
#define EM9118_TRISRC_EX                            1 //�ⴥ�������ɼ�
#define EM9118_TRI_EDGE                             0 //�ⴥ��ʱ���������ɼ�
#define EM9118_TRI_LEVEL                            1 //�ⴥ��ʱ��ƽ�����ɼ�
#define EM9118_TRI_UP                               0 //�ⴥ��ʱ�����أ��ߵ�ƽ�������ɼ�
#define EM9118_TRI_DOWN                             1 //�ⴥ��ʱ�½��أ��͵�ƽ�������ɼ�


//AD�ɼ���Χ
#define EM9118_AD_RANGE_N10_10V                      0L //��10V
#define	EM9118_AD_RANGE_N5_5V                        1L //��5V
#define	EM9118_AD_RANGE_0_20MA                       2L //0~20mA

//������ʽ
#define EM9118_CT_MODE_COUNT                         0 //����
#define EM9118_CT_MODE_HFREQ                         1 //���Ƶ
#define EM9118_CT_MODE_LFREQ                         3 //���Ƶ

//����������ܽŹ���
#define EM9118_DO_MODE_DO                            0 //���������
#define EM9118_DO_MODE_PWM                           1 //PWM
#define EM9118_DO_MODE_OCLK                          2 //OCLK���ɼ�ʱ�����

extern "C"
{

I32 _stdcall EM9118_DeviceCreate();
//�������ܣ������豸
//��ڲ�����
//      ��
//����ֵ��-1�������豸ʧ��
//        ����ֵΪ�豸��������Ժ���豸��ز����о�Ҫʹ���䷵��ֵ

void _stdcall EM9118_DeviceClose( I32 hDevice );
//�������ܣ��ر��豸��ͬʱ�ͷ��豸��ռ����Դ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//����ֵ����

I32 _stdcall EM9118_CmdConnect( I32 hDevice, char* strIP, I32 ipBC, I32 cmdPort, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ���������˿�
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//             strIP���豸IP
//              ipBC��strIP�ĳ��ȣ��˲���Ϊ0ʱ��ʾstrIP����0Ϊ�������ַ�����
//           cmdPort������˿ںš�
//         timeOutMS����ʱ��������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_DataConnect( I32 hDevice, I32 dataPort, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ��������ݶ˿ڣ����ô˺���֮ǰ�����ȵ���EM9118_CmdConnect
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//          dataPort�����ݶ˿ںš�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

void _stdcall EM9118_CmdClose( I32 hDevice, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ��ر�����˿�
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

void _stdcall EM9118_DataClose( I32 hDevice, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ��ر����ݶ˿�
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_AdChIsInFifo( I32 hDevice, I32 isInFifo[18], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ�����ADͨ�������Ƿ���뻺������ֻ��ָ����ͨ�����ܹ����뻺����
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//          isInFifo��18�ֽ����飬ÿһ��Ԫ�ض�Ӧһ·AD��0��ʾ��Ӧͨ��������FIFO,1��ʾ����FIFO
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_AdSetRange( I32 hDevice, I32 rangeInx, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ�����AD�ɼ���Χ��ע��Ҫ���豸����һ��
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//          rangeInx���ɼ���Χ
//                    0����10V
//                    1����5V
//                    2��0~20mA
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_AdReadZeroFullCode( I32 hDevice, I16 zeroCode[18], I16 fullCode[18], I32 timeOutMS = EM9118_TIMOUT_MS );
//��ȡAD������ȣ�������һ���û�ʹ�ò���

I32 _stdcall EM9118_AdWriteZero( I32 hDevice, I32 chNo, I16 zeroCode, I32 timeOutMS = EM9118_TIMOUT_MS );
//д��AD��㣬������һ���û�ʹ�ò���

I32 _stdcall EM9118_AdWriteFull( I32 hDevice, I32 chNo, I16 fullCode, I32 timeOutMS = EM9118_TIMOUT_MS );
//д��AD���ȣ�������һ���û�ʹ�ò���

I32 _stdcall EM9118_AdChGetCode( I32 hDevice, I32 chInx, U32 bytesCount, I8* codeBuffer, I16* adCode, U32* adCodeCount );
//�������ܣ����ӻ������л��ָ��ͨ����ADԭ��ֵ�����������ݵ���EM9118_HcReadData�õ�
//��ڲ�����
//         hDevice���豸�����EM9118_DeviceCreate��������ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ָADʹ��ͨ������ţ�����ʹ����AD5��AD6����ͨ������chInx=0ʱ��ʾҪȡ��AD5��ֵ��chInx=1ʱ��ʾҪȡ��AD6��ֵ
//      codeBuffer�����ݻ���������EM9118_HcReadDataӦ������ͬ��
//���ڲ�����
//            adCode��ADԭ��ֵ����Ҫ�û�����ռ�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_AdChCodeToValue( I32 hDevice, I32 chNo, I16 iCode, F64* adValue );
//�������ܣ���ADԭ��ֵת��������ֵ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~18
//             iCode��ԭ��ֵ
//���ڲ�����
//           adValue��AD����ֵת���������ѹֵ����Ҫ�û�����ռ�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_AdChBatchCodeToValue( I32 hDevice, I32 chNo, I16* pCode, I32 codeCount, F64* adValue );
//�������ܣ���ADһ��ԭ��ֵת��������ֵ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~18
//             pCode��ԭ��ֵ���飬16λ�з������Σ�һ�����EM9118_AdChGetCode�õ�
//         codeCount��pCode����������Ԫ�ظ���
//���ڲ�����
//           adValue��AD����ֵת���������ѹֵ����Ҫ�û�����ռ䣬��Ԫ�ظ���Ӧ����codeCount
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_HcSetGroupFreq( I32 hDevice,  F64 groupFreq, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ�������Ƶ��
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//         groupFreq����Ƶ�ʣ�1~450000Hz
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_HcSetTriCount( HANDLE hDevice, U32 triCount, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ������ⴥ���������˺���ֻ���ⴥ���ұ��ش���ʱ����Ч
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//          triCount������������1��4294967295
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��


I32 _stdcall EM9118_HcStart( I32 hDevice, I32 clkSrc, I32 triSrc, I32 edgeOrLevel, I32 upOrDown, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ�����Ӳ�����Ʋɼ�
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//            clkSrc��ʱ��Դ��0��ʱ�ӣ�1��ʱ��
//            triSrc������Դ��0�ڲ���1�ⲿ
//       edgeOrLevel��0���ⴥ��ʱ���������ɼ���1���ⴥ��ʱ��ƽ�����ɼ�
//          upOrDown��0���ⴥ��ʱ�����أ��ߵ�ƽ�������ɼ���1���ⴥ��ʱ�½��أ��͵�ƽ�������ɼ�
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_HcStop( I32 hDevice, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ�ֹͣӲ�����Ʋɼ�
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//���ڲ�����
//                ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_HcReadData( I32 hDevice, I32 byteCount, I8* codeBuffer, I32* realByteCount, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ���Ӳ�����Ʋɼ�������ʹ�ô˺������زɼ����ADԭ��ֵ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//         byteCount��Ҫ��ȡ���ֽ�����
//���ڲ�����
//        codeBuffer�����ݻ��������飬��Ҫ�û����䣬Ԫ�ظ�������ΪbyteCount
//     realByteCount��ʵ�ʶ��������ֽ�������Ҫ�û�����
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_CtChGetCode( I32 hDevice, I32 chInx, U32 bytesCount, I8* codeBuffer, U32* ctCode, U32* ctCodeCount );
//�������ܣ����ӻ������л��ָ��ͨ���ļ�����ԭ��ֵ�����������ݵ���EM9118_HcReadData�õ�
//��ڲ�����
//         hDevice���豸�����EM9118_DeviceCreate��������ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ֵ�����ļ�ʹ��ͨ������ţ�����ʹ����CT2��CT3����ͨ������chInx=0ʱ��ʾҪȡ��CT2��ֵ��chInx=1ʱ��ʾҪȡ��CT3��ֵ
//      codeBuffer�����ݻ���������EM9118_HcReadDataӦ������ͬ��
//���ڲ�����
//          ctCode��������ԭ��ֵ����Ҫ�û�����ռ�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_CtChBatchCodeToValue( I32 hDevice, I32 chNo, U32* pCode, I32 codeCount, F64* ctValue );
//�������ܣ���������һ��ԭ��ֵת��������ֵ������ʱת��������Ǽ���ֵ����Ƶת�������Ƶ��ֵ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~4
//             pCode��ԭ��ֵ���飬32λ�޷������Σ�һ�����EM9118_AdChGetCode�õ�
//         codeCount��pCode����������Ԫ�ظ���
//���ڲ�����
//           ctValue������ʱ�Ǽ���ֵ����Ƶʱ��Ƶ��ֵ����Ҫ�û�����ռ䣬��Ԫ�ظ���Ӧ����codeCount
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_EcChGetCode( I32 hDevice, I32 chInx, U32 bytesCount, I8* codeBuffer, I32* ecCode, U32* ecCodeCount );
//�������ܣ����ӻ������л��ָ��ͨ���ı�����ԭ��ֵ�����������ݵ���EM9118_HcReadData�õ�
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ֵ�����ļ�ʹ��ͨ�������
//        codeBuffer�����ݻ���������EM9118_HcReadDataӦ������ͬ��
//���ڲ�����
//            ecCode��������ԭ��ֵ����Ҫ�û�����ռ�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_DoSetMode( I32 hDevice, I8 doMode1, I8 doMode2, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ�����DO�ܽŹ���
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//           doMode1��DO1���ܣ�0���������;1,PWM1;2,OCLK;
//           doMode2��DO2���ܣ�0���������;1,PWM2;
//���ڲ�����
//                  ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_DiAll( I32 hDevice, I8 iStatus[4], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ��õ�����ͨ��������ֵ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//���ڲ�����
//           iStatus��4�ֽ����飬iStatus[0]~iStatus[3]��ӦDI1~DI4
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_DoAll( I32 hDevice, I8 oStatus[2], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ���������ͨ��������ֵ�������Ӧ��������������Ϊ���룬���Ӧ��������������Ч
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//           oStatus��2�ֽ����飬oStatus[0]~oStatus[1]��ӦDO1~DO2
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_EcClear( I32 hDevice, I32 chClear[EM9118_MAXECCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ�����������ֵ����
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//           chClear��2Ԫ�����飬ÿһ��Ԫ�ض�Ӧһ·��������1��ʾ��Ӧͨ������,0��ʾ��Ӧͨ��������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_EcReadCodeAll( I32 hDevice, I32 abCode[2], I32 zCode[2], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ���ȡ����������ֵ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//���ڲ�����
//            abCode��������ABֵ��32λ�з������飬��Ԫ�ظ���Ϊ2����Ҫ�û�����ռ䡣
//             zCode������������ֵ���豸��ʱ��֧�ִ˹���
//
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_CtChIsInFifo( I32 hDevice, I32 isInFifo[EM9118_MAXCTCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����ü�����ͨ���Ƿ����FIFO
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//          isInFifo��4Ԫ�����飬ÿһ��Ԫ�ض�Ӧһ·��������0��ʾ��Ӧͨ��������FIFO,1��ʾ����FIFO
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_CtSetFreqBase( I32 hDevice, I32 chNo, F64 freqBase_ms, F64* real_ms, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ�����ָ��ͨ���ļ�������Ƶ��׼�������ڣ��Ժ���Ϊ��λ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~4
//       freqBase_ms����Ƶ��׼���ڣ��Ժ���Ϊ��λ,0.001~1000
//���ڲ�����
//           real_ms��ʵ�ʲ�Ƶ��׼������������freqBase_msһ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_CtSetModeAll( I32 hDevice, I8 ctMode[EM9118_MAXCTCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ���������·�������Ĺ�����ʽ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//            ctMode��������������ʽ��4Ԫ����������
//                     0������
//                     1�����Ƶ
//                     2�����㣬��ɴ�ֵ����Ҫ�������Ӧ�����豸������ȷ����
//                     3�����Ƶ
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_CtClear( I32 hDevice, I32 chNo, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ�ָ��ͨ�����������㣬������ֻ���ڼ�����ʽ�²������壬���ִ�к�Ὣ��Ӧͨ������Ϊ����������ʽ	
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1~4
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_CtReadCodeAll( I32 hDevice, U32 ctCode[EM9118_MAXCTCHCNT], I32 timeOutMS );
//�������ܣ���ȡ����·��������ԭ��ֵ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//���ڲ�����
//            ctCode��������ԭ��ֵ������Ǽ�����ʽ���Ǽ���ֵ������ǲ�Ƶ����Ҫ�������ת����Ƶ��ֵ
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_EcChIsInFifo( I32 hDevice, I32 isInFifo[EM9118_MAXECCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����ñ�����ͨ���Ƿ����FIFO
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//          isInFifo��2Ԫ�����飬ÿһ��Ԫ�ض�Ӧһ·��������0��ʾ��Ӧͨ��������FIFO,1��ʾ����FIFO
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_GetFifoAdChCount( I32 hDevice );
I32 _stdcall EM9118_GetFifoCtChCount( I32 hDevice );
I32 _stdcall EM9118_GetFifoEcChCount( I32 hDevice );

I32 _stdcall EM9118_GetFifoGroupByteCount( I32 hDevice, I32* byteCount );
//�������ܣ��������ã��õ�FIFO��ÿ�����ݵ��ֽ���
//         ���ô˺����������������ĺ�����ÿ���ֽ������ܻᷢ���仯
//         EM9118_AdChIsInFifo
//         EM9118_CtChIsInFifo
//         EM9118_EcChIsInFifo
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//���ڲ�����
//         byteCount������ÿ���ֽ���
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_PwmStartAll( I32 hDevice, I8 startOrStop[EM9118_MAXPWMCHCNT], I8 is90[EM9118_MAXPWMCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ��趨����ͨ����PWM�����ʼ����ֹͣ
//��ڲ�����
//                hDevice���豸�����EM9118_DeviceCreate��������ֵ
//            startOrStop�������������飬����Ԫ��0~1��ӦPWM1~PWM2����PWM1Ϊ����
//                         startOrStop[0]=0��ֹͣ���
//                         startOrStop[0]=1���������
//                   is90����λ�������飬����Ԫ��0~1��ӦPWM1~PWM2����PWM1Ϊ����
//                         is90[0]=0������ͺ�90��
//                         is90[0]=1��������ͺ�90��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_PwmSetPulse( I32 hDevice, I32 chNo, double freq, double dutyCycle, double* realFreq, double* realDutyCycle, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ��趨ָ��ͨ����PWM����������
//��ڲ�����
//                hDevice���豸�����EM9118_DeviceCreate��������ֵ
//                   chNo��ͨ���ţ�1~2
//                   freq�����Ƶ�ʡ�160Hz~100KHz����ĳЩƵ���»�����
//              dutyCycle��ռ�ձȡ�0~1��������ڵ�λȡ�������Ƶ�ʣ����Ƶ��Խ�ͣ��ɵ��ڵĵ�λԽ�ࡣ
//���ڲ�����
//               realFreq����ʵƵ��ֵ�����������������趨Ƶ�ʺ���ʵƵ��֮�����Щ���
//          realDutyCycle����ʵռ�ձ�ֵ�����������������趨ռ�ձȺ���ʵռ�ձ�֮�����Щ���
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_PwmIsOver( I32 hDevice, I8 isOver[EM9118_MAXPWMCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����ƶ�������������������£��ж�PWM����Ƿ����
//��ڲ�����
//                hDevice���豸�����EM9118_DeviceCreate��������ֵ
//                 isOver���Ƿ���ɣ�����Ԫ��0~1��ӦPWM1~2����PWM1Ϊ����
//                           isOver[0]=0�����û�����
//                           isOver[0]=1������Ѿ����
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_PwmSetCount( I32 hDevice, I32 chNo, U32 setCount, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ��趨����������
//��ڲ�����
//                hDevice���豸�����EM9118_DeviceCreate��������ֵ
//                   chNo��ͨ���ţ�1~2
//               setCount����������������Ϊ�����ʾ�������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_CSVOpen( I32 hDevice, char* dirPath, I32 pathLen );
//�������ܣ���ʼ��CVS��ʷ����д�����������
//��ڲ�����
//          devNo���豸�ţ���1��ʼ
//        dirPath�������ʷ�ļ���·��������󳤶Ȳ��ܳ���256
//        pathLen��·�������ȣ����Ϊ0��ʾdisPath����0��β���ַ�����
//                ���򽫻���ָ��Ŀ¼���Զ�������yy-mm-dd-hh-MM-ss-1.cvs���ļ���������������ʱ����,-1��ʾ��һ���ļ���ÿ���ļ�512MB���ҡ�����512MB���ļ�����˳������-2��-3����
//���ڲ�����
//                ��
//����ֵ��0��ʾû�д���

I32 _stdcall EM9118_CSVClose( I32 hDevice );
//�������ܣ��ر���ʷ�����ļ�
//��ڲ�����
//          devNo���豸�ţ���1��ʼ
//���ڲ�����
//                ��
//����ֵ��0��ʾû�д���

I32 _stdcall EM9118_CSVWriteValue( I32 hDevice, I8* pCode, U32 codeBC );
//�������ܣ���ָ���Ĳɼ�ԭ��ֵת��������ֵ��д�뵽�����ļ��У�Ҫ�ȵ���EM9118_CVSOpen���������ݽ��޷����档
//��ڲ�����
//          devNo���豸�ţ���1��ʼ
//          pCode��װ��ԭ��ֵ������
//         codeBC�������ֽ���
//���ڲ�����
//                ��
//����ֵ��0��ʾû�д���

I32 _stdcall EM9118_DFWOpen( I32 hDevice, char* dirPath, I32 pathLen );
//�������ܣ���ʼ����ʷ����д�����������
//��ڲ�����
//          devNo���豸�ţ���1��ʼ
//        dirPath�������ʷ�ļ���·��������󳤶Ȳ��ܳ���256
//        pathLen��·�������ȣ����Ϊ0��ʾdisPath����0��β���ַ�����
//                ���򽫻���ָ��Ŀ¼���Զ�������yy-mm-dd-hh-MM-ss-1.dat���ļ���������������ʱ����,-1��ʾ��һ���ļ���ÿ���ļ�512MB���ҡ�����512MB���ļ�����˳������-2��-3����
//���ڲ�����
//                ��
//����ֵ��0��ʾû�д���

I32 _stdcall EM9118_DFWClose( I32 hDevice );
//�������ܣ��ر���ʷ�����ļ�
//��ڲ�����
//          devNo���豸�ţ���1��ʼ
//���ڲ�����
//                ��
//����ֵ��0��ʾû�д���

I32 _stdcall EM9118_DFWrite( I32 hDevice, I8* pCode, U32 codeBC );
//�������ܣ���ָ���Ĳɼ�ԭ��ֵд�뵽�����ļ��У�Ҫ�ȵ���EM9118_DFWOpen���������ݽ��޷����档
//��ڲ�����
//          devNo���豸�ţ���1��ʼ
//          pCode��װ��ԭ��ֵ������
//         codeBC�������ֽ���
//���ڲ�����
//                ��
//����ֵ��0��ʾû�д���

I32 _stdcall EM9118_DFROpen( char* filePathName, I32 pathLen );
//�������ܣ���ʼ����ʷ���ݶ�ȡ��������
//��ڲ�����
//        dirPath������·��������ʷ�ļ���
//���ڲ�����
//                ��
//����ֵ����0ֵ��ʾ�ļ����
//        0��ʾ���ļ�ʧ�ܡ�

I32 _stdcall EM9118_DFRClose( I32 hDFR );
//�������ܣ���ʼ����ʷ���ݶ�ȡ��������
//��ڲ�����
//           hDFR����ʷ�ļ����
//���ڲ�����
//                ��
//����ֵ����

I32 _stdcall EM9118_DFRCodeBufferSize( I32 hDFR, U32 groupCount, U32* bufferSize );
//�������ܣ���ʼ����ʷ���ݶ�ȡ��������
//��ڲ�����
//           hDFR����ʷ�ļ����
//     groupCount��Ҫ��ȡ��ÿͨ�����ݸ�����
//���ڲ�����
//     bufferSize��������Ԫ�ظ�����ÿ��Ԫ����16λ���Σ�����ʹ�����ֵ�����ݻ���������ռ䡣
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFRReadCodeByGroupInx( I32 hDFR, I8* codeBuf, U32 groupCodeCount, F64 codeBeginInx, U32* realReadCount );
//�������ܣ�����ʷ�ļ�ָ��λ�ö�������
//��ڲ�����
//              hDFR����ʷ�ļ����
//           codeBuf�����ݻ���������Ҫ�û�����ռ䣬���С���Ե���EM9118_DFRCodeBufferSize�õ�
//    groupCodeCount��Ҫ��ȡ��ÿͨ�����ݸ�����
//      codeBeginInx����ȡ��ʼ��λ�á����Ϊ-1�����ʾ����һ�ζ�ȡ�Ľ�����ʼ��ȡ��
//���ڲ�����
//     realReadCount��ʵ�ʶ�ȡ��ÿͨ�����ݸ�����
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFRAdChGetCode( I32 hDFR, I32 chInx, U32 bytesCount, I8* originalCode, I16* adCode, U32* adCodeCount );
//�������ܣ����ӻ������л��ָ��ͨ����ADԭ��ֵ�����������ݵ���EM9118_DFRReadCodeByGroupInx�õ�
//��ڲ�����
//            hDFR����ʷ�ļ����
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ָADʹ��ͨ������ţ�����ʹ����AD5��AD6����ͨ������chInx=0ʱ��ʾҪȡ��AD5��ֵ��chInx=1ʱ��ʾҪȡ��AD6��ֵ
//      codeBuffer�����ݻ���������EM9118_DFRReadCodeByGroupInxӦ������ͬ��
//���ڲ�����
//            adCode��ADԭ��ֵ����Ҫ�û�����ռ�
//       adCodeCount��ADԭ��ֵ��������Ҫ�û�����ռ�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_DFRAdCodeToValue( I32 hDFR, I32 chNo, I16 adCode, F64* adValue );
//�������ܣ�ADԭ��ת��������ֵ
//��ڲ�����
//              hDFR����ʷ�ļ����
//              chNo��ͨ���ţ�1~18
//            adCode��ADԭ��ֵ
//���ڲ�����
//           adValue��ת���������ѹ��VΪ��λ��������mAΪ��λ
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFRAdBatchCodeToValue( I32 hDFR, I32 chNo, I16* pCode, I32 codeCount, F64* adValue );
//�������ܣ���һ��ADԭ��ת��������ֵ
//��ڲ�����
//              hDFR����ʷ�ļ����
//              chNo��ͨ���ţ�1~18
//             pCode��ADԭ��ֵ��������ַ
//         codeCount�����������ݸ���
//���ڲ�����
//           adValue��ת���������ѹ��VΪ��λ��������mAΪ��λ
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFRGetAdChValue( I32 hDFR, I32 chNo, I8* codeBuf, U32 groupCodeCount, F64* adValue );
//�˺���ֻ��Ϊ�˱��ֺ��ϳ���ļ����ԣ�һ���û�����ʹ��

I32 _stdcall EM9118_DFRCtChGetCode( I32 hDFR, I32 chInx, U32 bytesCount, I8* originalCode, U32* ctCode, U32* ctCodeCount );
//�������ܣ����ӻ������л��ָ��ͨ����ADԭ��ֵ�����������ݵ���EM9118_DFRReadCodeByGroupInx�õ�
//��ڲ�����
//            hDFR����ʷ�ļ����
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ָCTʹ��ͨ������ţ�����ʹ����CT2��CT3����ͨ������chInx=0ʱ��ʾҪȡ��CT2��ֵ��chInx=1ʱ��ʾҪȡ��CT3��ֵ
//      codeBuffer�����ݻ���������EM9118_DFRReadCodeByGroupInxӦ������ͬ��
//���ڲ�����
//          ctCode��CTԭ��ֵ����Ҫ�û�����ռ�
//     ctCodeCount��CTԭ��ֵ��������Ҫ�û�����ռ�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_DFRCtBatchCodeToValue( I32 hDFR, I32 chNo, U32* pCode, I32 codeCount, F64* ctValue );
//�������ܣ�CTԭ��ת��������ֵ
//��ڲ�����
//              hDFR����ʷ�ļ����
//              chNo��ͨ���ţ�1~4
//            ctCode��CTԭ��ֵ
//���ڲ�����
//           ctValue��ת������������޵�λ����Ƶ��HzΪ��λ
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFREcChGetCode( I32 hDFR, I32 chInx, U32 bytesCount, I8* originalCode, I32* ctCode, U32* ctCodeCount );
//�������ܣ����ӻ������л��ָ��ͨ����ADԭ��ֵ�����������ݵ���EM9118_DFRReadCodeByGroupInx�õ�
//��ڲ�����
//            hDFR����ʷ�ļ����
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ָCTʹ��ͨ������ţ�����ʹ����CT2��CT3����ͨ������chInx=0ʱ��ʾҪȡ��CT2��ֵ��chInx=1ʱ��ʾҪȡ��CT3��ֵ
//      codeBuffer�����ݻ���������EM9118_DFRReadCodeByGroupInxӦ������ͬ��
//���ڲ�����
//          ctCode��CTԭ��ֵ����Ҫ�û�����ռ�
//     ctCodeCount��CTԭ��ֵ��������Ҫ�û�����ռ�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9318_DFRIoGetCode( I32 hDFR, U32 bytesCount, I8* originalCode, U16* ioCode, U32* ctCodeCount );
//�������ܣ����ӻ������л��ָ��ͨ����IOԭ��ֵ�����������ݵ���EM9118_DFRReadCodeByGroupInx�õ�
//��ڲ�����
//            hDFR����ʷ�ļ����
//      codeBuffer�����ݻ���������EM9118_DFRReadCodeByGroupInxӦ������ͬ��
//���ڲ�����
//          ioCode��IOԭ��ֵ����Ҫ�û�����ռ�
//     ctCodeCount��IOԭ��ֵ��������Ҫ�û�����ռ�
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_DFRGetFreq( I32 hDFR, F64* daqFreq );
//�������ܣ��õ���ʷ�ļ��Ĳɼ�Ƶ��
//��ڲ�����
//              hDFR����ʷ�ļ����
//���ڲ�����
//           daqFreq���ɼ�Ƶ�ʣ���Ҫ�û�����ռ�
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFRGetGroupTotal( I32 hDFR, F64* groupTotal );
//�������ܣ��õ���ʷ�ļ���������������������ʹ�����ֵ���ԺͲɼ�Ƶ�ʼ������ʷ����ʱ��
//��ڲ�����
//              hDFR����ʷ�ļ����
//���ڲ�����
//        groupTotal��������
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFRGetAdIsInfifo( I32 hDFR, I8* isInFifo );
//�������ܣ��õ���ʷ�ļ���������ʹ��ADͨ��
//��ڲ�����
//              hDFR����ʷ�ļ����
//���ڲ�����
//     isInFifo��18�ֽ����飬0~17Ԫ�ض�ӦAD1~AD18
//               0��ʾ��Ӧͨ����ֹ��1��ʾ��Ӧͨ��ʹ��
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFRGetCtIsInfifo( I32 hDFR, I8* isInFifo );
//�������ܣ��õ���ʷ�ļ���������ʹ�ܼ�����ͨ��
//��ڲ�����
//              hDFR����ʷ�ļ����
//���ڲ�����
//     isInFifo��4�ֽ����飬0~3Ԫ�ض�Ӧ������1~������18
//               0��ʾ��Ӧͨ����ֹ��1��ʾ��Ӧͨ��ʹ��
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFRGetEcIsInfifo( I32 hDFR, I8* isInFifo );
//�������ܣ��õ���ʷ�ļ���������ʹ�ܼ�����ͨ��
//��ڲ�����
//              hDFR����ʷ�ļ����
//���ڲ�����
//     isInFifo��2�ֽ����飬0~1Ԫ�ض�Ӧ������1~������18
//               0��ʾ��Ӧͨ����ֹ��1��ʾ��Ӧͨ��ʹ��
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFRGetClkSource( I32 hDFR, I32* clkSource );
//�������ܣ��õ���ʷ�ļ���������ʱ��Դ
//��ڲ�����
//              hDFR����ʷ�ļ����
//���ڲ�����
//         clkSource��ʱ��Դ
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_DFRGetEtrSource( I32 hDFR, I32* etrSource );
//�������ܣ��õ���ʷ�ļ���������ʱ��Դ
//��ڲ�����
//              hDFR����ʷ�ļ����
//���ڲ�����
//         etrSource������Դ
//����ֵ��0ֵ�ɹ�
//        <0��ʾʧ�ܣ�������ο�EM9118_Error.H��

I32 _stdcall EM9118_OlFileOpen( I8* filePathName );
//�������ܣ��������ļ�
//��ڲ�����
//      filePathName���ļ�·��
//����ֵ��-1,���ļ�ʧ��
//        ����ֵΪ�ļ����

I32 _stdcall EM9118_OlFileClose( I32 fileHandle );
//�������ܣ��ر������ļ�
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//����ֵ��-1,�ļ������Ч
//        0��ʾ�رճɹ�

I32 _stdcall EM9118_OlGetDataBytesCount( I32 fileHandle );
//�������ܣ������������ļ��еõ��������������ֽ�λ��λ
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//����ֵ��>0,��������
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9118_OlGetAdEnCh( I32 fileHandle, I8 enCh[EM9118_MAXADCHCNT] );
//�������ܣ������������ļ��еõ�ADʹ��ͨ����
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//���ڲ�����
//            enCh������AD��ʹ��ͨ��������Ϊ18���ֽ�����
//����ֵ��>=0,����ʹ��ͨ������
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9118_OlGetCtEnCh( I32 fileHandle, I8 enCh[EM9118_MAXCTCHCNT] );
//�������ܣ������������ļ��еõ�������ʹ��ͨ����
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//���ڲ�����
//            enCh������AD��ʹ��ͨ��������Ϊ18���ֽ�����
//����ֵ��>=0,����ʹ��ͨ������
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9118_OlGetEcEnCh( I32 fileHandle, I8 enCh[EM9118_MAXCTCHCNT] );
//�������ܣ������������ļ��еõ�������ʹ��ͨ����
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//���ڲ�����
//            enCh������AD��ʹ��ͨ��������Ϊ18���ֽ�����
//����ֵ��>=0,����ʹ��ͨ������
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9118_OlGetGroupBytesCount( I32 fileHandle );
//�������ܣ������������ļ��еõ�ÿ���ֽ�����Ҳ����ÿ�β�������õ������ֽ���
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//����ֵ��>0,ÿ���ֽ���
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9118_OlGetGroupFreq( I32 fileHandle, F64* groupFreq );
//�������ܣ������������ļ��еõ���Ƶ��ֵ
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//���ڲ�����
//       groupFreq����HzΪ��λ�Ĳɼ�Ƶ��
//����ֵ��=0,��ʾ�ɹ�

I32 _stdcall EM9118_OlGetOriginalCode( I32 fileHandle, I32 readPos, U32 bytesCount, U8* originalCode, U32* realBC );
//�������ܣ������������ļ��л�ȡԭʼ����
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//         readPos����ȡλ�ã���һ���ɼ�ͨ����һ���ɼ���Ķ�ȡλ��Ϊ0�����Ϊ-1��ʾ�ӵ�ǰλ�ö�ȡ
//      bytesCount��Ҫ��ȡ���ֽ�����
//���ڲ�����
//    originalCode�����ݻ���������Ҫ�û����䣬���СΪbytesCount
//          realBC��ʵ�ʶ�ȡ���ֽ���
//����ֵ��>0,�����ļ���ǰָ���λ�ã���������ȷ����һ�ζ�ȡ��λ��
//        <0,��ʾ��ȡʧ��

I32 _stdcall EM9118_OlDirOpen( I8* path );
//�������ܣ��������ļ�Ŀ¼���˺��������ϸ�ʽ��Ŀ¼�򿪣�׼�����մ洢����˳������ļ�
//��ڲ�����
//            path��Ŀ¼��·������Ŀ¼�ڲ��ṹ����������ļ��洢�̵Ľṹһ�¡�
//                  �����ļ��洢��Ŀ¼�ṹ����Ŀ¼�������ļ��У�ÿ�������ļ������������ļ���
//����ֵ��-1,���ļ�ʧ��
//        ����ֵΪ�ļ����

I32 _stdcall EM9118_OlGetAdChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, I16* adChCode, U32* adCodeCount );
//�������ܣ������������ļ��л�ȡADԭʼ����
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ֵ�����ļ�ʹ��ͨ������ţ�����ʹ����AD5��AD6����ͨ������chInx=0ʱ��ʾҪȡ��AD5��ֵ��chInx=1ʱ��ʾҪȡ��AD6��ֵ
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//        adChCode��ָ��ͨ�������ݽ������飬��Ҫ�û�����ռ䣬����Ϊ16λ�з������ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9118_OlGetGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���adCodeCount����ȡ���顣
//     adCodeCount��adChCode���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

I32 _stdcall EM9118_OlGetAdChValue( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, F64* adChValue, U32* adValueCount );
//�������ܣ������������ļ��л�ȡAD����ֵ
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ֵ�����ļ�ʹ��ͨ������ţ�����ʹ����AD5��AD6����ͨ������chInx=0ʱ��ʾҪȡ��AD5��ֵ��chInx=1ʱ��ʾҪȡ��AD6��ֵ
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//        adChValue��ָ��ͨ�������ݽ������飬��Ҫ�û�����ռ䣬����Ϊ64λ˫���ȸ��㣬�����СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9118_OlGetGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���adCodeCount����ȡ���顣
//     adValueCount��adChValue���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

I32 _stdcall EM9118_OlGetCtChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, U32* ctChCode, U32* ctCodeCount );
//�������ܣ������������ļ��л�ȡ������ԭʼ����
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ֵ�����ļ�ʹ��ͨ������ţ�����ʹ����CT2��3����ͨ������chInx=0ʱ��ʾҪȡ��CT2��ֵ��chInx=1ʱ��ʾҪȡ��CT3��ֵ
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//        ctChCode��ָ��ͨ�������ݽ������飬��Ҫ�û�����ռ䣬����Ϊ32λ�޷������ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9118_OlGetGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���adCodeCount����ȡ���顣
//     ctCodeCount��ctChCode���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

I32 _stdcall EM9118_OlGetCtChValue( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, F64* ctChValue, U32* ctValueCount );
//�������ܣ������������ļ��л�ȡ����������ֵ������Ǽ�����������ʽ����ԭ��ֵ����Ƶ��ʽ����Ƶ��ֵ
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ֵ�����ļ�ʹ��ͨ������ţ�����ʹ����CT2��3����ͨ������chInx=0ʱ��ʾҪȡ��CT2��ֵ��chInx=1ʱ��ʾҪȡ��CT3��ֵ
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//       ctChValue��ָ��ͨ�������ݽ������飬��Ҫ�û�����ռ䣬����Ϊ64λ˫���ȸ����ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9118_OlGetGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���ctValueCount����ȡ���顣
//    ctValueCount��ctChValue���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

I32 _stdcall EM9118_OlGetEcChCode( I32 fileHandle, I32 chInx, U32 bytesCount, U8* originalCode, I32* ecChCode, U32* ecCodeCount );
//�������ܣ������������ļ��л�ȡ������ԭʼ����
//��ڲ�����
//      fileHandle���ļ������EM9118_OlFileOpen�ķ���ֵ
//           chInx��ͨ��������0~ʵ��ʹ��ͨ����-1�������ͨ��������ֵ�����ļ�ʹ��ͨ�������
//      bytesCount��originalCode���������ݵ��ֽ�����
//    originalCode��ԭʼ�뻺����
//���ڲ�����
//        ecChCode��ָ��ͨ�������ݽ������飬��Ҫ�û�����ռ䣬����Ϊ16λ�з������ͣ������СΪbytesCount/ÿ���ֽ�����ÿ���ֽ���������EM9118_OlGetGroupBytesCount�����õ����û�Ҳ���Է���bytesCount������Ȼ���ٸ���adCodeCount����ȡ���顣
//     ecCodeCount��ecChCode���ص���Ч���ݸ�����=0���ʾ�����ء�
//����ֵ��<0,��ʾ����ʧ��

//////////////////////////////////��EM9106�й�ϵ�ĺ���////////////////////////////////////////////////////
I32 _stdcall EM9106_IoSetDirAndMode( I32 hDevice, I8 ioDir[3], I8 doMode[4], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9106B������IO���������������ʱ���ùܽŹ���
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//             ioDir������������3Ԫ������
//                    ioDir[0]��ӦIO1��IO8
//                    ioDir[1]��ӦIO9��IO16
//                    ioDir[2]��ӦIO17��IO24
//            doMode��IO�ܽŹ��ܣ�4Ԫ������
//                    doMode[0]��ӦIO17��0��ʾ���ڿ�������1��ʾPWM1
//                    doMode[1]��ӦIO18��0��ʾ���ڿ�������1��ʾPWM2
//                    doMode[2]��ӦIO19��0��ʾ���ڿ�������1��ʾOCLK
//                    doMode[3]��ӦIO20��0��ʾ���ڿ�������1��ʾOTR
//���ڲ�����
//                  ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9106_IoSetAll( I32 hDevice, I8 oStatus[EM9106_MAXIOCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ���������ͨ��������ֵ�������Ӧ��������������Ϊ���룬���Ӧ��������������Ч
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//           oStatus��24�ֽ����飬oStatus[0]~oStatus[23]��ӦIO1~IO24
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9106_IoGetAll( I32 hDevice, I8 iStatus[EM9106_MAXIOCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ��õ�����ͨ��������ֵ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//���ڲ�����
//           iStatus��24�ֽ����飬iStatus[0]~iStatus[23]��ӦIO1~IO24
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

//////////////////////////////////��EM9106�й�ϵ�ĺ���////////////////////////////////////////////////////
I32 _stdcall EM9318_IoSetMode( I32 hDevice, I32 chNo, I8 ioMode, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9318������IO���������������ʱ���ùܽŹ���
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//              chNo��ͨ���ţ�1��8
//            ioMode��IO�ܽŹ���
//                    0�����������룬1�����������
//                    ����ɿ���������ʱ��IO1��IO4ͬʱ���ԽӼ����ź����ڼ�������Ƶ
//                                        IO5��IO8ͬʱ���Խӱ������ź�
//                    ����ɿ��������ʱ��IO5��IO8��PWMʹ�ܺ����PWM�źţ�������������Ч
//���ڲ�����
//                  ��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9318_IoSetAll( I32 hDevice, I8 oStatus[EM9318_MAXIOCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9318������IO���״̬
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//           oStatus��8�ֽ����飬oStatus[0]~oStatus[7]��ӦIO1~IO8
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9318_IoGetAll( I32 hDevice, I8 iStatus[EM9318_MAXIOCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9318���õ�����ͨ��������ֵ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//���ڲ�����
//           iStatus��8�ֽ����飬iStatus[0]~iStatus[8]��ӦIO1~IO8
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9318_PwmStartAll( I32 hDevice, I8 startOrStop[EM9318_MAXPWMCHCNT], I8 is90[EM9318_MAXPWMCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9318���趨����ͨ����PWM�����ʼ����ֹͣ
//��ڲ�����
//                hDevice���豸�����EM9118_DeviceCreate��������ֵ
//            startOrStop�������������飬����Ԫ��0~3��ӦPWM1~PWM4����PWM1Ϊ����
//                         startOrStop[0]=0��ֹͣ���
//                         startOrStop[0]=1���������
//                   is90����λ�������飬����Ԫ��0~3��ӦPWM1~PWM4����PWM1Ϊ����
//                         is90[0]=0������ͺ�90��
//                         is90[0]=1��������ͺ�90��
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9318_PwmSetPulse( I32 hDevice, I32 chNo, double freq, double dutyCycle, double* realFreq, double* realDutyCycle, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9318���趨ָ��ͨ����PWM����������
//��ڲ�����
//                hDevice���豸�����EM9118_DeviceCreate��������ֵ
//                   chNo��ͨ���ţ�1~4
//                   freq�����Ƶ�ʡ�1Hz~500KHz����ĳЩƵ���»�����
//              dutyCycle��ռ�ձȡ�0~1��������ڵ�λȡ�������Ƶ�ʣ����Ƶ��Խ�ͣ��ɵ��ڵĵ�λԽ�ࡣ
//���ڲ�����
//               realFreq����ʵƵ��ֵ�����������������趨Ƶ�ʺ���ʵƵ��֮�����Щ���
//          realDutyCycle����ʵռ�ձ�ֵ�����������������趨ռ�ձȺ���ʵռ�ձ�֮�����Щ���
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9318_PwmIsOver( I32 hDevice, I8 isOver[EM9318_MAXPWMCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9318�����ƶ�������������������£��ж�PWM����Ƿ����
//��ڲ�����
//                hDevice���豸�����EM9118_DeviceCreate��������ֵ
//                 isOver���Ƿ���ɣ�����Ԫ��0~3��ӦPWM1~4����PWM1Ϊ����
//                           isOver[0]=0�����û�����
//                           isOver[0]=1������Ѿ����
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9318_PwmSetCount( I32 hDevice, I32 chNo, U32 setCount, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9318���趨����������
//��ڲ�����
//                hDevice���豸�����EM9118_DeviceCreate��������ֵ
//                   chNo��ͨ���ţ�1~4
//               setCount����������������Ϊ�����ʾ�������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9318_EcClear( I32 hDevice, I32 chClear[EM9318_MAXECCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9318������������ֵ����
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//           chClear��4Ԫ�����飬ÿһ��Ԫ�ض�Ӧһ·��������1��ʾ��Ӧͨ������,0��ʾ��Ӧͨ��������
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9318_EcReadCodeAll( I32 hDevice, I32 abCode[EM9318_MAXECCHCNT], I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9318����ȡ����������ֵ
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//���ڲ�����
//            abCode��������ABֵ��4Ԫ��32λ�з������飬ÿ��Ԫ�ض�Ӧһ·����������Ҫ�û�����ռ䡣
//
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9118_DiIsInFifo( I32 hDevice, I32 isInFifo, I32 timeOutMS = EM9118_TIMOUT_MS );
//�������ܣ����������EM9318��EM9118���Ʋ�Ʒ�����ÿ������������FIFO
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//          isInFifo��0��ʾ������FIFO��1��ʾ����FIFO
//
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

I32 _stdcall EM9318_IoGetCode( I32 hDevice, U32 bytesCount, I8* originalCode, U16* diCode, U32* diCodeCount );
//�������ܣ����������EM9318��EM9118���Ʋ�Ʒ,���ӻ������л��ָ��ͨ���Ŀ�����ֵ�����������ݵ���EM9118_HcReadData�õ�
//��ڲ�����
//           hDevice���豸�����EM9118_DeviceCreate��������ֵ
//        codeBuffer�����ݻ���������EM9118_HcReadDataӦ������ͬ��
//���ڲ�����
//            diCode������������ֵ����Ҫ�û�����ռ�
//            diCodeCount�����ݸ���
//����ֵ��0��ʾ�ɹ���<0��ʾʧ��

};

#endif