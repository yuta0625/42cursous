仮想マシンとはなんですか？
仮想マシン(Virtual Machine)とは、ハイパーバイザーと呼ばれるソフトウェアの上で、物理マシンのCPU・メモリ・ディスクなどを仮想化して、独立したOS(ゲストOS)を動かせる仕組みです。

仮想マシンを使う目的
・環境を完全に分離(開発環境・検証環境・本番環境の切り分け)
・OSを自由に選べる(Mac上でLinuxやWindowsを動かす)
・安全性(壊してもホストOSに影響なし)
・効率的なリソース利用(１台の物理PCを復数の仮想マシンで共有)
例：VirtualBox, VMware, Hyper-V, AWSのEC2など

選択したオペレーティングシステム
ー＞Debaianである(確認の方法： cat /etc/os-release)

CentOSとDebianの基本的な違いに関して
debaian 系統の違い
ー＞debianに関しては、コミュニティ主導である。Rocky（Red Hat Enterprise Linux）であり企業向けである。
パッケージ管理の違い
->.deb(dpkg/apt)がdebainであり.rpm(yum/dnf)がCentOS(Rockyである)
コミュニティ向けである　ｰ> debian
大企業向けであるかのちがいがある -> centos/Rocky

aptとaptitudeの違いに関して
aptとaptitudeの違いは、機能の方向性(シンプル vs 高機能)と依存関係の扱いにある
aptの特徴
特徴
・シンプルで初心者向け
・基本的な操作に最適（install / update / upgrade / remove など）
・コマンド構造が分かりやすい
・Debian公式が「日常利用に推奨」
sudo apt update
sudo apt install nginx
sudo apt remove docker.io

aptitudeの特徴
aptitude は apt の代わりに使える上位互換的ツール で、以下が強み。
特徴
・依存関係の衝突を自動的に解決する力が強い
・対話的に「解決案」を複数提示してくれる
・CLI だけでなく TUI（画面型インターフェイス） でも操作可能
・より高機能＆柔軟
sudo aptitude

APPArmorについて
->Linuxのセキュリティ機能の一つで、特定のアプリケーションが何をしてよいかを細かく制限するしくみである
アプリごとに「できること」と「できないこと」をプロファイルで決めて、もしアプリが乗っ取られても被害を最小化する仕組み。
→ ファイアウォールが“外との通信”を守るものだとすると、AppArmor は“アプリの行動”そのものを制限する防御。
AppArmor が何を制限できる？
アプリごとに以下のような動作を制限できる：
・どのファイルにアクセスできるか
・どのディレクトリを読めるか/書けるか
・ネットワーク通信の可否
・どのシステムコールを実行できるか
・使用できる権限の範囲
・たとえばnginxに対して
・/var/www/html は読み取りOK
・/etc/passwd はアクセス禁止
・書き込みは特定ディレクトリだけ
・ポート80だけ通信可能
といったように、きめ細かく制限できる。

AppArmorとpwqualityの違いと機能
・AppArmor → アプリができることを制限
・pwquality → パスワードの条件を制限
しかし、これらは セキュリティの異なるレイヤー を守っているだけで、仕組みは別物。

pwquality（libpam-pwquality）
→ 家の“鍵を強くする”機能
弱いパスワード＝弱い鍵
強いパスワード＝強い鍵
→ 家（システム）に入るための鍵の強度を管理。

AppArmor
→ “家の中での行動制限”を決める機能
侵入した人が
どの部屋に入れる？
何を触ってよい？
何を実行できる？を制限する。
➡ 深い階層の「行動の自由度」を制御する仕組み。

スクリプトを10分ごとにすべて表示する
root の crontab に追加した monitoring.sh の行だけを削除すれば OK です。
ただし、絶対に「削除してよいのは “追加した一行だけ”」であって、他は触ってはいけないという点が重要です。

sudo crontab -u root -eで設定した一文を消す
*/10 * * * * /usr/local/bin/monitoring.sh

ufwサービスが開始されていることを確認してください
sudo ufw status

sshサービスが開始されていることを確認してください
sudo systemctl status ssh

選択したオペレーティングシステムがDebianまたはRockyであることを確認してください。
cat /etc/os-release

評価対象の学生がログインを持つユーザーが仮想マシンに存在することを要求します。
そのユーザーが追加され、「sudo」及び　「user42」グループに属していることを確認する必要がある
getent passwd yuta42

新しいユーザーを作成する。科目のルールを尊重し、任意のパスワードを割り当てる。
sudo adduser <新しいlogin名>
科目で要求されたルールを仮想マシンにどのように設定したかを説明する必要がある。
パスワードのルールに関してのまとめ
このパスワードに関しては、etc/pam.d/common-passwordに記述してある

グループの作成
sudo groupadd testgroup
ユーザーをグループに追加する
sudo usermod -aG testgroup testuser
確認の方法
id testuser

このパスワードポリシーの利点と、実装の長所と短所の説明をおこなう
パスワードの安全性の強化があげられる。
ｰ>長いパスワードや多種の文字が必要になるため解読が難しくなる
rootユーザーと一般ユーザーで共通して強力なポリシーを適用可能である
pam+pwqualityという観点での評価
ｰ>設定ファイルを数カ所変更するだけで、システム全体を一括適用できる
(/etc/pam.d/common-password や pwquality.conf を変更することで、passwd コマンドなど標準のパスワード変更手段すべてに同じルールを適用できます。)

しかし、ユーザー側の目線にたつとパスワードの複雑さがまし、覚えづらいというデメリットも挙げられる

現在のホスト名の確認
hostname
ホスト名を変更する
sudo hostnamectl set-hostname yuta42
sudo reboot

元のホスト名に戻す方法
sudo hostnamectl set-hostname login42
sudo reboot

パーティションの確認
lsblk

LVMの確認
sudo pvdisplay
sudo vgdisplay
sudo lvdisplay

LVMの簡単な説明に関して
LVM はストレージを柔軟に管理するための仕組みで、
まず物理ディスクを Physical Volume（PV）として登録し、
複数の PV をまとめて Volume Group（VG）を作ります。
そして、その VG の中に必要なサイズで Logical Volume（LV）を作成し、
その LV を実際のファイルシステムとして使用します。
LVM を使うと、後から LV のサイズを拡張したり、別ディスクを追加して容量を増やすなど、柔軟なストレージ管理が可能になります。

PV（Physical Volume）
物理ディスクやパーティションを LVM 用に初期化したもの。
LVM の最小単位（原材料）。

VG（Volume Group）
複数の PV をまとめて1つの大きなストレージプールにしたもの。
（あなたの理解：*“物理的なところをまとめたもの” → 正しい）

LV（Logical Volume）
VG の中から必要な容量だけ切り出した仮想ディスク。
（あなたの理解：*“まとめた中から必要なだけ切った領域” → 完全に正しい）
ここにファイルシステム（ext4/xfs）を作って /home や /var などとしてマウントする。

sudoがインストールされているかを確認する
which sudo
-> /usr/bin/sudo

上で説明した通りにsudoグループにユーザーを割り当てる
id ユーザー名で確認することができるｒ

sudoの価値・目的を説明
sudoは、root権限を必要とするコマンドを一時的に実行できる仕組みであり、rootとして常に
ログインするより安全な運用を行うことができる
必要な操作だけを昇格して行うことができるため、システムの誤操作やセキュリティリスクを大幅に減らすことができる。
さらに、sudoは実行履歴がログとして残るため、「誰がいつ何を実行したか」が管理でき、監査にも有効である。

sudoの厳密なルールに関しての設定
sudoersを直接編集しないなのは、sudoers本体には不要なDefaultsを書かず、危険を避けるよなつくりにしている。
そして,@includedir /etc/sudoers.dここから/etc/sduoers.d/sudo_configの内容を読み込み
sudoの新しいルールとして適応させる。
＜sudo_configの中身に関して＞
sudoers の設定で、requiretty を有効にすることで、
sudo の実行を必ず対話的な端末からに制限しています。
また lecture = always を設定し、sudo 実行時には必ず警告メッセージが表示されます。
パスワードの試行回数も 3 回に制限し、ログは /var/log/sudo/ に保存されるよう設定しています。
sudo.logの味方としては
sudo cat /var/log/sudo/sudo.logで確認を行う

sudoコマンドを実行して、ログが更新されるかを確認すれば大丈夫

sudoパスワード認証を一回通すとその後確認が行われない理由
sudoersにタイムスタンプが書かれていないとデフォルト値が設定せれるためである。
timestamp_timeout=15   （15分）

TTYモードを有効にする
Defaults requiretty

セキュリティ強化のため。
✔ 理由1：自動スクリプトによる sudo の悪用を防ぐ
スクリプトやマルウェアが sudo を勝手に動かすことを防げる。
✔ 理由2：人間の操作による sudo のみ許可する
TTY が必要ということは、「ユーザーが端末上で操作している」証拠。
✔ 理由3：Born2beRoot 科目で明確に要求されている
だからあなたの sudo_config にも入っている：

ufwが正しくインストールされているかの確認
ufwがinstallされているかの確認
sudo ufw status

sudoが正常に動作しているか
sudo systemctl status ufw

現在の有効ルールに関して
sudo ufw status verbose

ufwとはなにか
ufwはLinuxのファイアーウォール機能であるnetfilter/iptablesをより簡単に、安全に操作するためのフロントエンドツールである。

なぜ必要化？　
サーバーに対する外部から通信を制御し、必要なポートだけを許可し、それ以外を遮断するためである。
とくにSSHやWebサーバーのような、公開ポートを明確に管理することで攻撃リスクを下げる

ufw自体はファイアウォールではなく、iptablesに設定ルールを書き込むためのフロントエンドです。
ユーザーは allow や deny といった簡単なコマンドを使いますが、実際には ufw が複雑な iptables ルールを自動生成し、netfilter に対してパケットフィルタリングを行います

ポート8080を開くルールを追加する
sudo ufw allow 8080/tcp

追加した8080ルールを消去する
sudo ufw delete allow 8080/tcp

sshがインストールされているかの確認
sudo systemctl status ssh

SSHの定義について
SSH（Secure Shell）は、ネットワーク経由でリモートのコンピュータに安全に接続するためのプロトコルです。
通信が暗号化されるので、パスワードやデータが盗聴されるのを防げます。
サーバー管理に広く使われ、セキュアで信頼性が高い通信手段です。

sshがポート4242のみを使用していることの確認
sudo grep Port etc/ssh/sshd_config

実際にサービスが　4242番でLISTENしているかの確認
sudo ss -tlnp | grep ssh

rootでログインできないことを確認する
ssh root@localhost -p 4242

他のユーザーでのログインを確認する
ssh testuser@localhost -p 4242

「cron」とはなにかについて説明をする。
cronとは、Linuxで定期的に自動実行されるタスク(ジョブ)を管理する仕組みである。
決められた日次・周期でコマンドやスクリプトを自動で実行してくれる。

sudo crontab -u root -e
上記で設定を行うことができる

最後に、評価対象の学生は、サーバーの起動時にスクリプトの実行を停止する必要がありますが、スクリプト自体は変更しないでください。この点を確認するには、最後にもう一度サーバーを再起動する必要があります。起動時に、スクリプトが同じ場所にまだ存在していること、権限が変更されていないこと、そして変更されていないことを確認する必要があります。何かが期待どおりに動作しない、または明確に説明されていない場合は、評価はここで終了します。

oot の crontab に追加した monitoring.sh の行だけを削除すれば OK です。
ただし、絶対に「削除してよいのは “追加した一行だけ”」であって、他は触ってはいけないという点が重要です。

sudo crontab -u root -eで設定した一文を消す
*/10 * * * * /usr/local/bin/monitoring.sh

monitoring.sh の説明（完成版）

私が作成した monitoring.sh は、サーバーの状態をリアルタイムで監視し、
wall を用いてシステム情報を全ユーザーに通知するスクリプトです。
Born2beRoot の課題で要求されている全ての要素を取得できるように設計しています。

1. システムアーキテクチャ（Architecture）
uname -a により OS・カーネル情報を取得し、システムの基本情報を表示します。

2. CPU の情報
physical id を数えて 物理 CPU コア数を取得しています。

processor の行数を数えて 仮想 CPU（vCPU）数を取得しています。
/proc/cpuinfo を直接参照することでより正確な値が得られます。

3. メモリ使用量（RAM）
free --mega を使用し、
メモリの総量

使用量

使用率（%）
を算出しています。

4. ディスク使用量（Disk）

df -m の結果から /boot を除外し、

全体容量（GB）

使用容量（MB）

使用率

を計算しています。
複数パーティションを合計するため awk を使用しています。

5. CPU 負荷（CPU load）

vmstat 1 2 で idle 値を取得し、
100 – idle を計算することで現在の CPU 使用率を求めています。
より正確な負荷計測ができます。

6. 最終起動時間（Last boot）

who -b により、最後にシステムがブートした時刻を取得します。

7. LVM の使用有無

lsblk | grep lvm の結果で LVM が使われているか判定し、
yes / no で表示します。

8. TCP 接続数

ss -ta | grep ESTAB により、
現在確立されている TCP 接続数をカウントしています。

9. ログイン中のユーザー数

users | wc -w により、現在ログインしているユーザー数を取得しています。

10. ネットワーク情報（IP / MAC）

hostname -I で IP アドレス

ip link の結果から MAC アドレス

を抽出しています。

11. sudoコマンド実行回数

journalctl _COMM=sudo | grep COMMAND を数え、
sudo が何回使われたかをカウントしています。
これは課題で必須の要件です。

12. 最終出力（wall）について

wall を使うことで、
ログイン中の全ユーザーに監視結果を一斉送信しています。

これは Born2beRoot の指定通りで、
評価者の前で正しく動いていることを見せられるようにしています。　
