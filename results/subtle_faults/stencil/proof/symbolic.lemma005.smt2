; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x10547 (bvmul arg0_2 arg2_0)))
(let ((?x721906 (bvmul (_ bv4294967295 32) ?x10547)))
(let ((?x17056 (bvmul arg0_2 arg2_1)))
(let ((?x721569 (bvadd ?x17056 ?x721906)))
(and (distinct ?x721569 (_ bv0 32)) true))))))
(check-sat)
