; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x438048 (bvmul arg0_9 arg1_4)))
(let ((?x201509 (bvmul (_ bv4294967295 32) ?x438048)))
(let ((?x430345 (bvmul arg0_9 arg1_5)))
(let ((?x479416 (bvadd ?x430345 ?x201509)))
(and (distinct ?x479416 (_ bv0 32)) true))))))
(check-sat)
