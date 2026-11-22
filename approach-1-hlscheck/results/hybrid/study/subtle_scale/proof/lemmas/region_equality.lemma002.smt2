; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_0 () (_ BitVec 32))
(assert
 (let ((?x293957 ((_ extract 28 0) arg0_0)))
(let ((?x516079 (concat ?x293957 (_ bv3 3))))
(let ((?x362606 (bvmul (_ bv4294967295 32) ?x516079)))
(and (distinct ?x362606 (_ bv0 32)) true)))))
(check-sat)
