; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x508983 (bvmul arg0_1 arg0_6)))
(let ((?x537 (bvmul (_ bv4294967295 32) ?x508983)))
(let ((?x432214 (bvmul arg0_1 arg0_9)))
(let ((?x399281 (bvadd ?x432214 ?x537)))
(and (distinct ?x399281 (_ bv0 32)) true))))))
(check-sat)
