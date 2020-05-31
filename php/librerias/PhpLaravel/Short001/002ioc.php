//How to use abstraction using higher-level and lower-level modules
interface PaymentInterface {
    public function notify();
}
class PaymentGateway implements PaymentInterface {
    public function notify() {
	return "You have paid through Stripe";
    }
}
class PaymentNotification {
    protected $notify;
    public function __construct(PaymentInterface $notify) {
        $this->notify = $notify;
    }
    public function notifyClient() {
        return "We have received your payment. {$this->notify->notify()}";
    }
}
$notify = new PaymentNotification(new PaymentGateway);
echo $notify->notifyClient();
