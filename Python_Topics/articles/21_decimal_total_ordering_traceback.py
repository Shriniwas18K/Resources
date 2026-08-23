# In Python Numeric types should be handled using 
# Decimal type for financial calculations.This
# prevents rounding errors in floating point 
# numbers providing exact decimal arithmetic.
# The Money class is example of well built 
# Python object, and financial,geometric 
# types should be built similarly.

# To support arithmetic operations we need to
# support all operator methods, thus we use 
# functools.total_ordering to generate all 
# __operator__ methods, if __eq__, and one 
# operator method is implemented.

# NotImplemented is special constant.It is used
# for handling invalid type artithmetics. It is
# returned not raised. Only for __operator__ 
# methods and it is required for total_ordering.
# If someone compares str to Money then we return
# NotImplemented rather than raising TypeError.

# To have graceful error handling and debugging
# we use traceback moduel, which prints the 
# traceback of where error occured.

from decimal import Decimal, ROUND_HALF_EVEN
from functools import total_ordering
from typing import Any, Self
import traceback

def _to_decimal(value: Any)->Decimal:
    """
    Convert to Decimal safely. Use str 
    conversion to avoid float binary 
    rounding artifacts.
    """
    if isinstance(value,Decimal):
        return value
    if isinstance(value,(int,float,str)):
        return Decimal(str(value))
    raise TypeError(f"Unsupported amount type: {
    type(value)=}")

@total_ordering     
#  implements <=,>,>= when __eq__ 
#  and __lt__ is implemented
class Money:
    """
    An immutable-ish value object representing an\
    amount in a currency.
    - __repr__/__str__ : provides dev vs user
    friendly representations.
    - __eq__/__lt__ : provides currency aware
    comparisons.
    - __hash__ : allows to use as elements in set
    or key in dicts.
    """
    def __init__(self, amount: Any, currency: str
    ) -> None:
        cur = currency.upper()
        if len(cur) != 3 or not cur.isalpha():
            raise ValueError(f"Currency must be a\
            3-letter code like 'USD'.")
        dec = _to_decimal(amount)
        # Normalize to 2 decimal places (cents)
        # using Bankers rounding.
        q = Decimal("0.01")
        self._amount = dec.quantize(q,
                        rounding=ROUND_HALF_EVEN) 
        # converts 10.000 and 10 to 10.00
        self._currency = cur

    @property
    def amount(self) -> Decimal:
        return self._amount

    @property
    def currency(self) -> str:
        return self._currency
    
    def __repr__(self) -> str:
        return f"Money(Decimal({self.amount}),'{
        self.currency}')"
    
    def __str__(self) -> str:
        return f"{self.amount} {self.currency}"

    def __eq__(self, other: Self) -> bool:
        if not isinstance(other, Money):
            return NotImplemented
        return (self.amount, self.currency) == 
        (other.amount, other.currency)

    def __lt__(self, other: Self) -> bool:
        if not isinstance(other, Money):
            return NotImplemented
        if self.currency != other.currency:
            raise TypeError(
            f"Cannot order amounts in diffirent\
            currencies: "
            f"{self.currency} vs {other.currency}"
            )

    # allows to use as keys in sets and dictionary
    def __hash__(self) -> int:
        cents = int((self.amount * Decimal("100"))
            .to_integral_value())
        return hash((self.currency,cents))

m1 = Money(100, "usd")
m2 = Money(Decimal("100"), "USD")
print(m1 == m2)

m3 = Money(Decimal("10"),  "USD")
print(m1 > m3)

s = {m1, m2, m3}
print(s)

e1 = Money("100","EUR")
try:
   print(e1 < m1)
except Exception as e:
   print(repr(e))
   traceback.print_exc()
